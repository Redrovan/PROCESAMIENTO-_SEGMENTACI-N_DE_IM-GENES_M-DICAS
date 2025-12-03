/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QFrame *leftPanel;
    QVBoxLayout *leftLayout;
    QGroupBox *groupFilters;
    QVBoxLayout *filtersLayout;
    QCheckBox *chkDnCNN;
    QCheckBox *chkGaussian;
    QCheckBox *chkCLAHE;
    QCheckBox *chkEqualize;
    QCheckBox *chkSobel;
    QCheckBox *chkCanny;
    QCheckBox *chkDeepFGS;
    QPushButton *btnSelectImage;
    QPushButton *btnProcess;
    QGroupBox *boxSliders;
    QGridLayout *sliderGrid;
    QSlider *sldGaussianKernel;
    QDoubleSpinBox *spCLAHE;
    QSlider *sldCannyT1;
    QSpinBox *spCanny1;
    QSpinBox *spCanny2;
    QSlider *sldCLAHE;
    QLabel *label1;
    QLabel *label2;
    QSlider *sldCannyT2;
    QLabel *label3;
    QLabel *label4;
    QSpinBox *spSobel;
    QSlider *sldSobelKernel;
    QLabel *label5;
    QSpinBox *spGaussian;
    QGroupBox *boxLogicOps;
    QHBoxLayout *hboxLayout;
    QLabel *lblOr;
    QLabel *lblXor;
    QLabel *lblNot;
    QLabel *lblAnd;
    QFrame *rightPanel;
    QGridLayout *gridImages;
    QGroupBox *boxFinal;
    QLabel *lblFinal;
    QGroupBox *boxOriginal;
    QLabel *lblOriginal;
    QGroupBox *boxLungs;
    QLabel *lblLungs;
    QGroupBox *boxPre;
    QLabel *lblPre;
    QGroupBox *boxBones;
    QLabel *lblBones;
    QGroupBox *boxHeart;
    QLabel *lblHeart;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1434, 785);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        leftPanel = new QFrame(centralwidget);
        leftPanel->setObjectName(QString::fromUtf8("leftPanel"));
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        groupFilters = new QGroupBox(leftPanel);
        groupFilters->setObjectName(QString::fromUtf8("groupFilters"));
        filtersLayout = new QVBoxLayout(groupFilters);
        filtersLayout->setObjectName(QString::fromUtf8("filtersLayout"));
        chkDnCNN = new QCheckBox(groupFilters);
        chkDnCNN->setObjectName(QString::fromUtf8("chkDnCNN"));

        filtersLayout->addWidget(chkDnCNN);

        chkGaussian = new QCheckBox(groupFilters);
        chkGaussian->setObjectName(QString::fromUtf8("chkGaussian"));

        filtersLayout->addWidget(chkGaussian);

        chkCLAHE = new QCheckBox(groupFilters);
        chkCLAHE->setObjectName(QString::fromUtf8("chkCLAHE"));

        filtersLayout->addWidget(chkCLAHE);

        chkEqualize = new QCheckBox(groupFilters);
        chkEqualize->setObjectName(QString::fromUtf8("chkEqualize"));

        filtersLayout->addWidget(chkEqualize);

        chkSobel = new QCheckBox(groupFilters);
        chkSobel->setObjectName(QString::fromUtf8("chkSobel"));

        filtersLayout->addWidget(chkSobel);

        chkCanny = new QCheckBox(groupFilters);
        chkCanny->setObjectName(QString::fromUtf8("chkCanny"));

        filtersLayout->addWidget(chkCanny);

        chkDeepFGS = new QCheckBox(groupFilters);
        chkDeepFGS->setObjectName(QString::fromUtf8("chkDeepFGS"));

        filtersLayout->addWidget(chkDeepFGS);

        btnSelectImage = new QPushButton(groupFilters);
        btnSelectImage->setObjectName(QString::fromUtf8("btnSelectImage"));

        filtersLayout->addWidget(btnSelectImage);

        btnProcess = new QPushButton(groupFilters);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));

        filtersLayout->addWidget(btnProcess);


        leftLayout->addWidget(groupFilters);

        boxSliders = new QGroupBox(leftPanel);
        boxSliders->setObjectName(QString::fromUtf8("boxSliders"));
        sliderGrid = new QGridLayout(boxSliders);
        sliderGrid->setObjectName(QString::fromUtf8("sliderGrid"));
        sldGaussianKernel = new QSlider(boxSliders);
        sldGaussianKernel->setObjectName(QString::fromUtf8("sldGaussianKernel"));
        sldGaussianKernel->setMinimum(1);
        sldGaussianKernel->setMaximum(31);
        sldGaussianKernel->setValue(5);
        sldGaussianKernel->setOrientation(Qt::Horizontal);

        sliderGrid->addWidget(sldGaussianKernel, 0, 1, 1, 1);

        spCLAHE = new QDoubleSpinBox(boxSliders);
        spCLAHE->setObjectName(QString::fromUtf8("spCLAHE"));
        spCLAHE->setMinimum(1.000000000000000);
        spCLAHE->setMaximum(10.000000000000000);
        spCLAHE->setValue(3.000000000000000);

        sliderGrid->addWidget(spCLAHE, 1, 2, 1, 1);

        sldCannyT1 = new QSlider(boxSliders);
        sldCannyT1->setObjectName(QString::fromUtf8("sldCannyT1"));
        sldCannyT1->setMinimum(0);
        sldCannyT1->setMaximum(255);
        sldCannyT1->setValue(80);
        sldCannyT1->setOrientation(Qt::Horizontal);

        sliderGrid->addWidget(sldCannyT1, 3, 1, 1, 1);

        spCanny1 = new QSpinBox(boxSliders);
        spCanny1->setObjectName(QString::fromUtf8("spCanny1"));
        spCanny1->setMinimum(0);
        spCanny1->setMaximum(255);
        spCanny1->setValue(80);

        sliderGrid->addWidget(spCanny1, 3, 2, 1, 1);

        spCanny2 = new QSpinBox(boxSliders);
        spCanny2->setObjectName(QString::fromUtf8("spCanny2"));
        spCanny2->setMinimum(0);
        spCanny2->setMaximum(255);
        spCanny2->setValue(160);

        sliderGrid->addWidget(spCanny2, 4, 2, 1, 1);

        sldCLAHE = new QSlider(boxSliders);
        sldCLAHE->setObjectName(QString::fromUtf8("sldCLAHE"));
        sldCLAHE->setMinimum(1);
        sldCLAHE->setMaximum(10);
        sldCLAHE->setValue(3);
        sldCLAHE->setOrientation(Qt::Horizontal);

        sliderGrid->addWidget(sldCLAHE, 1, 1, 1, 1);

        label1 = new QLabel(boxSliders);
        label1->setObjectName(QString::fromUtf8("label1"));

        sliderGrid->addWidget(label1, 4, 0, 1, 1);

        label2 = new QLabel(boxSliders);
        label2->setObjectName(QString::fromUtf8("label2"));

        sliderGrid->addWidget(label2, 1, 0, 1, 1);

        sldCannyT2 = new QSlider(boxSliders);
        sldCannyT2->setObjectName(QString::fromUtf8("sldCannyT2"));
        sldCannyT2->setMinimum(0);
        sldCannyT2->setMaximum(255);
        sldCannyT2->setValue(160);
        sldCannyT2->setOrientation(Qt::Horizontal);

        sliderGrid->addWidget(sldCannyT2, 4, 1, 1, 1);

        label3 = new QLabel(boxSliders);
        label3->setObjectName(QString::fromUtf8("label3"));

        sliderGrid->addWidget(label3, 0, 0, 1, 1);

        label4 = new QLabel(boxSliders);
        label4->setObjectName(QString::fromUtf8("label4"));

        sliderGrid->addWidget(label4, 2, 0, 1, 1);

        spSobel = new QSpinBox(boxSliders);
        spSobel->setObjectName(QString::fromUtf8("spSobel"));
        spSobel->setMinimum(1);
        spSobel->setMaximum(7);
        spSobel->setValue(3);

        sliderGrid->addWidget(spSobel, 2, 2, 1, 1);

        sldSobelKernel = new QSlider(boxSliders);
        sldSobelKernel->setObjectName(QString::fromUtf8("sldSobelKernel"));
        sldSobelKernel->setMinimum(1);
        sldSobelKernel->setMaximum(7);
        sldSobelKernel->setValue(3);
        sldSobelKernel->setOrientation(Qt::Horizontal);

        sliderGrid->addWidget(sldSobelKernel, 2, 1, 1, 1);

        label5 = new QLabel(boxSliders);
        label5->setObjectName(QString::fromUtf8("label5"));

        sliderGrid->addWidget(label5, 3, 0, 1, 1);

        spGaussian = new QSpinBox(boxSliders);
        spGaussian->setObjectName(QString::fromUtf8("spGaussian"));
        spGaussian->setMinimum(1);
        spGaussian->setMaximum(31);
        spGaussian->setValue(5);

        sliderGrid->addWidget(spGaussian, 0, 2, 1, 1);


        leftLayout->addWidget(boxSliders);

        boxLogicOps = new QGroupBox(leftPanel);
        boxLogicOps->setObjectName(QString::fromUtf8("boxLogicOps"));
        hboxLayout = new QHBoxLayout(boxLogicOps);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lblOr = new QLabel(boxLogicOps);
        lblOr->setObjectName(QString::fromUtf8("lblOr"));
        lblOr->setMinimumSize(QSize(180, 120));

        hboxLayout->addWidget(lblOr);

        lblXor = new QLabel(boxLogicOps);
        lblXor->setObjectName(QString::fromUtf8("lblXor"));
        lblXor->setMinimumSize(QSize(180, 120));

        hboxLayout->addWidget(lblXor);

        lblNot = new QLabel(boxLogicOps);
        lblNot->setObjectName(QString::fromUtf8("lblNot"));
        lblNot->setMinimumSize(QSize(180, 120));

        hboxLayout->addWidget(lblNot);

        lblAnd = new QLabel(boxLogicOps);
        lblAnd->setObjectName(QString::fromUtf8("lblAnd"));
        lblAnd->setMinimumSize(QSize(180, 120));

        hboxLayout->addWidget(lblAnd);


        leftLayout->addWidget(boxLogicOps);


        mainLayout->addWidget(leftPanel);

        rightPanel = new QFrame(centralwidget);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        gridImages = new QGridLayout(rightPanel);
        gridImages->setObjectName(QString::fromUtf8("gridImages"));
        boxFinal = new QGroupBox(rightPanel);
        boxFinal->setObjectName(QString::fromUtf8("boxFinal"));
        lblFinal = new QLabel(boxFinal);
        lblFinal->setObjectName(QString::fromUtf8("lblFinal"));
        lblFinal->setGeometry(QRect(8, 34, 300, 200));
        lblFinal->setMinimumSize(QSize(300, 200));
        lblFinal->setScaledContents(true);

        gridImages->addWidget(boxFinal, 2, 1, 1, 1);

        boxOriginal = new QGroupBox(rightPanel);
        boxOriginal->setObjectName(QString::fromUtf8("boxOriginal"));
        lblOriginal = new QLabel(boxOriginal);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setGeometry(QRect(8, 34, 300, 200));
        lblOriginal->setMinimumSize(QSize(300, 200));
        lblOriginal->setScaledContents(true);

        gridImages->addWidget(boxOriginal, 0, 0, 1, 1);

        boxLungs = new QGroupBox(rightPanel);
        boxLungs->setObjectName(QString::fromUtf8("boxLungs"));
        lblLungs = new QLabel(boxLungs);
        lblLungs->setObjectName(QString::fromUtf8("lblLungs"));
        lblLungs->setGeometry(QRect(8, 34, 300, 200));
        lblLungs->setMinimumSize(QSize(300, 200));
        lblLungs->setScaledContents(true);

        gridImages->addWidget(boxLungs, 1, 0, 1, 1);

        boxPre = new QGroupBox(rightPanel);
        boxPre->setObjectName(QString::fromUtf8("boxPre"));
        lblPre = new QLabel(boxPre);
        lblPre->setObjectName(QString::fromUtf8("lblPre"));
        lblPre->setGeometry(QRect(8, 34, 300, 200));
        lblPre->setMinimumSize(QSize(300, 200));
        lblPre->setMaximumSize(QSize(365, 238));
        lblPre->setScaledContents(true);

        gridImages->addWidget(boxPre, 0, 1, 1, 1);

        boxBones = new QGroupBox(rightPanel);
        boxBones->setObjectName(QString::fromUtf8("boxBones"));
        lblBones = new QLabel(boxBones);
        lblBones->setObjectName(QString::fromUtf8("lblBones"));
        lblBones->setGeometry(QRect(8, 34, 300, 200));
        lblBones->setMinimumSize(QSize(300, 200));
        lblBones->setScaledContents(true);

        gridImages->addWidget(boxBones, 2, 0, 1, 1);

        boxHeart = new QGroupBox(rightPanel);
        boxHeart->setObjectName(QString::fromUtf8("boxHeart"));
        lblHeart = new QLabel(boxHeart);
        lblHeart->setObjectName(QString::fromUtf8("lblHeart"));
        lblHeart->setGeometry(QRect(8, 34, 300, 200));
        lblHeart->setMinimumSize(QSize(300, 200));
        lblHeart->setScaledContents(true);

        gridImages->addWidget(boxHeart, 1, 1, 1, 1);

        boxLungs->raise();
        boxHeart->raise();
        boxBones->raise();
        boxFinal->raise();
        boxOriginal->raise();
        boxPre->raise();

        mainLayout->addWidget(rightPanel);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Procesamiento de Im\303\241genes CT - Interciclo", nullptr));
        groupFilters->setTitle(QCoreApplication::translate("MainWindow", "Filtros de preprocesamiento", nullptr));
        chkDnCNN->setText(QCoreApplication::translate("MainWindow", "Filtro Deep Learning DN-CNN (ONNX)", nullptr));
        chkGaussian->setText(QCoreApplication::translate("MainWindow", "Gaussian Blur", nullptr));
        chkCLAHE->setText(QCoreApplication::translate("MainWindow", "CLAHE", nullptr));
        chkEqualize->setText(QCoreApplication::translate("MainWindow", "Equalize Histograma", nullptr));
        chkSobel->setText(QCoreApplication::translate("MainWindow", "Sobel (bordes)", nullptr));
        chkCanny->setText(QCoreApplication::translate("MainWindow", "Canny (bordes)", nullptr));
        chkDeepFGS->setText(QCoreApplication::translate("MainWindow", "Filtro Profundo FGS", nullptr));
        btnSelectImage->setText(QCoreApplication::translate("MainWindow", "Seleccionar Imagen CT", nullptr));
        btnProcess->setText(QCoreApplication::translate("MainWindow", "Procesar Imagen", nullptr));
        boxSliders->setTitle(QCoreApplication::translate("MainWindow", "Par\303\241metros Ajustables", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Canny Threshold 2", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "CLAHE Clip Limit", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Gaussian Kernel", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "Sobel Kernel", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "Canny Threshold 1", nullptr));
        boxLogicOps->setTitle(QCoreApplication::translate("MainWindow", "Operaciones L\303\263gicas", nullptr));
        lblOr->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
        lblXor->setText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
        lblNot->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
        lblAnd->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
        boxFinal->setTitle(QCoreApplication::translate("MainWindow", "Imagen Final Resaltada", nullptr));
        boxOriginal->setTitle(QCoreApplication::translate("MainWindow", "Imagen Original", nullptr));
        boxLungs->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n Pulmones", nullptr));
        boxPre->setTitle(QCoreApplication::translate("MainWindow", "Preprocesamiento", nullptr));
        boxBones->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n Huesos", nullptr));
        boxHeart->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n Coraz\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
