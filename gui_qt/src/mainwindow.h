#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QString>

#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSelectImage_clicked();
    void on_btnProcess_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat imagenOriginal;
    QString rutaSeleccionada;

    QPixmap cvMatToQPixmap(const cv::Mat &mat);
    void mostrarImagen(QLabel *label, const cv::Mat &img);
};

#endif
