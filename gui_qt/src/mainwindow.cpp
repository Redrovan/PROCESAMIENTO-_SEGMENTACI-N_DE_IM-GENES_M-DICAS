#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

#include "opencv_bridge.h"

// Pipeline
#include "itk_loader.h"
#include "preprocessing.h"
#include "segmentation.h"
#include "morphology.h"
#include "contours.h"
#include "utils.h"
#include "deep_denoise.h"

// Métricas
#include "metrics.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectImage_clicked()
{
    qDebug() << "--------------------------------------------";
    qDebug() << "  INICIO: Carga de Imagen CT";
    qDebug() << "--------------------------------------------";

    // <<< NUEVO: RAM antes de cargar imagen
    size_t ramAntes = obtenerUsoMemoriaRAM();
    qDebug() << " RAM antes de carga =" << ramAntes << "KB";

    rutaSeleccionada = QFileDialog::getOpenFileName(
        this,
        "Seleccionar imagen CT",
        "",
        "Imágenes CT (*.IMA *.dcm *.png *.jpg *.jpeg *.bmp)"
    );

    if (rutaSeleccionada.isEmpty())
        return;

    imagenOriginal = cargarIMA_ITK(rutaSeleccionada.toStdString());

    if (imagenOriginal.empty()) {
        QMessageBox::critical(this, "Error", "La imagen no pudo ser cargada. Verifique formato o si está dañada.");
        return;
    }

    // Convertir cualquier imagen a GRIS (si viene en RGB)
    if (imagenOriginal.channels() == 3)
        cv::cvtColor(imagenOriginal, imagenOriginal, cv::COLOR_BGR2GRAY);

    qDebug() << " Imagen cargada correctamente desde:";
    qDebug() << QString::fromStdString(rutaSeleccionada.toStdString());

    // <<< NUEVO: RAM después de cargar imagen
    size_t ramDespues = obtenerUsoMemoriaRAM();
    qDebug() << " RAM después de carga =" << ramDespues << "KB";

    // <<< NUEVO: RAM consumida solo por carga de imagen
    qDebug() << " RAM consumida por carga =" << (ramDespues - ramAntes) << "KB";

    mostrarImagen(ui->lblOriginal, imagenOriginal);
    ui->statusBar->showMessage("Imagen cargada correctamente.", 3000);
}


void MainWindow::on_btnProcess_clicked()
{
    qDebug() << "\n============================================";
    qDebug() << " INICIO DEL PIPELINE DE PROCESAMIENTO";
    qDebug() << "============================================";

    if (imagenOriginal.empty()) {
        QMessageBox::warning(this, "Error", "Primero seleccione una imagen.");
        return;
    }

    cv::Mat base = imagenOriginal.clone();
    cv::Mat pre;

    bool filtroUsado = false;

    // RAM ANTES
    size_t ramAntes = obtenerUsoMemoriaRAM();
    qDebug() << " RAM antes del procesamiento =" << ramAntes << "KB";

   
    qDebug() << "\n---  PREPROCESAMIENTO ---";

    if (ui->chkGaussian->isChecked())  { qDebug() << "Aplicando Gaussian..."; pre = filtroGaussian(base); filtroUsado = true; }
    if (ui->chkCLAHE->isChecked())     { qDebug() << "Aplicando CLAHE...";    pre = filtroCLAHE(base);    filtroUsado = true; }
    if (ui->chkEqualize->isChecked())  { qDebug() << "Aplicando Equalize..."; pre = filtroEqualize(base); filtroUsado = true; }
    if (ui->chkSobel->isChecked())     { qDebug() << "Aplicando Sobel...";    pre = filtroSobel(base);    filtroUsado = true; }
    if (ui->chkCanny->isChecked())     { qDebug() << "Aplicando Canny...";    pre = filtroCanny(base);    filtroUsado = true; }

    if (ui->chkDeepFGS->isChecked()) {
        qDebug() << "Aplicando FGS...";
        pre = aplicarFGS(base);
        filtroUsado = true;
    }

    if (ui->chkDnCNN->isChecked()) {
        qDebug() << "Aplicando DN-CNN...";

        std::string modelo = buscarModeloDnCNN();

        if (modelo.empty()) {
            QMessageBox::critical(this, "Error", "No se encontró el modelo dncnn_final.onnx.");
            pre = base.clone();
        } else {
            qDebug() << "Modelo detectado en:" << QString::fromStdString(modelo);
            pre = aplicarDnCNN(base);
            filtroUsado = true;
        }
    }

    if (!filtroUsado) {
        qDebug() << " No se usó ningún filtro → Imagen original usada.";
        pre = base.clone();
    }

    mostrarImagen(ui->lblPre, pre);

    
    qDebug() << "\n---  MÉTRICAS DE CALIDAD ---";

    double psnr = calcularPSNR(imagenOriginal, pre);
    double ssim = calcularSSIM(imagenOriginal, pre);

    qDebug() << " PSNR  =" << psnr;
    qDebug() << " SSIM  =" << ssim;

   
    qDebug() << "\n---  SEGMENTACIÓN ---";
    qDebug() << "Segmentando pulmones...";
    cv::Mat segPulmones = segmentarPulmones(pre);

    qDebug() << "Segmentando corazón...";
    cv::Mat segCorazon  = segmentarCorazon(pre);

    qDebug() << "Segmentando huesos...";
    cv::Mat segHuesos   = segmentarHuesos(pre);

    mostrarImagen(ui->lblLungs, segPulmones);
    mostrarImagen(ui->lblHeart, segCorazon);
    mostrarImagen(ui->lblBones, segHuesos);

    qDebug() << " Segmentaciones completadas.";

    qDebug() << "\n---  Guardando Histogramas ---";

    guardarHistogramaCSV(segPulmones, "hist_pulmones.csv");
    guardarHistogramaCSV(segCorazon,  "hist_corazon.csv");
    guardarHistogramaCSV(segHuesos,   "hist_huesos.csv");

    qDebug() << " Histogramas guardados.";

   
    qDebug() << "\n--- MORFOLOGÍA ---";

    cv::Mat mp = refinarPulmones(segPulmones);
    cv::Mat mc = refinarCorazon(segCorazon);
    cv::Mat mh = refinarHuesos(segHuesos);

    qDebug() << " Morfología aplicada.";

   
    qDebug() << "\n---  CONTORNOS ---";

    cv::Mat finalRGB;
    cv::cvtColor(imagenOriginal, finalRGB, cv::COLOR_GRAY2BGR);

    dibujarContornosColor(finalRGB, mp, cv::Scalar(0,255,0));
    dibujarContornosColor(finalRGB, mc, cv::Scalar(0,0,255));
    dibujarContornosColor(finalRGB, mh, cv::Scalar(255,255,0));

    mostrarImagen(ui->lblFinal, finalRGB);

    qDebug() << " Contornos dibujados.";

    size_t ramDespues = obtenerUsoMemoriaRAM();
    size_t ramUsada = ramDespues - ramAntes;

    qDebug() << "\n============================================";
    qDebug() << "RESUMEN GENERAL DEL PROCESAMIENTO";
    qDebug() << "============================================";
    qDebug() << "RAM antes       =" << ramAntes << "KB";
    qDebug() << "RAM después     =" << ramDespues << "KB";
    qDebug() << "RAM consumida   =" << ramUsada << "KB";
    qDebug() << "PSNR            =" << psnr;
    qDebug() << "SSIM            =" << ssim;
    qDebug() << "============================================";

    ui->statusBar->showMessage("Procesamiento completado.", 3000);
}


QPixmap MainWindow::cvMatToQPixmap(const cv::Mat &mat)
{
    if (mat.empty()) return QPixmap();

    cv::Mat rgb;

    if (mat.channels() == 1)
        cv::cvtColor(mat, rgb, cv::COLOR_GRAY2RGB);

    else if (mat.channels() == 3)
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);

    else {
        qDebug() << "Error: imagen con canales no soportados:" << mat.channels();
        return QPixmap();
    }

    return QPixmap::fromImage(
        QImage(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888)
    );
}

void MainWindow::mostrarImagen(QLabel *label, const cv::Mat &img)
{
    QPixmap px = cvMatToQPixmap(img);

    if (!px.isNull())
        label->setPixmap(px.scaled(
            label->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        ));
}
