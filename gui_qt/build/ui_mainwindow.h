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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *btnSelectImage;
    QPushButton *btnProcess;
    QGroupBox *groupFilters;
    QVBoxLayout *filtersLayout;
    QCheckBox *chkDnCNN;
    QCheckBox *chkGaussian;
    QCheckBox *chkCLAHE;
    QCheckBox *chkEqualize;
    QCheckBox *chkSobel;
    QCheckBox *chkCanny;
    QCheckBox *chkDeepFGS;
    QSpacerItem *verticalSpacer;
    QFrame *rightPanel;
    QGridLayout *gridImages;
    QGroupBox *boxOriginal;
    QVBoxLayout *vboxLayout;
    QLabel *lblOriginal;
    QGroupBox *boxPre;
    QVBoxLayout *vboxLayout1;
    QLabel *lblPre;
    QGroupBox *boxLungs;
    QVBoxLayout *vboxLayout2;
    QLabel *lblLungs;
    QGroupBox *boxHeart;
    QVBoxLayout *vboxLayout3;
    QLabel *lblHeart;
    QGroupBox *boxBones;
    QVBoxLayout *vboxLayout4;
    QLabel *lblBones;
    QGroupBox *boxFinal;
    QVBoxLayout *vboxLayout5;
    QLabel *lblFinal;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 850);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        leftPanel = new QFrame(centralwidget);
        leftPanel->setObjectName(QString::fromUtf8("leftPanel"));
        leftPanel->setMinimumWidth(260);
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        btnSelectImage = new QPushButton(leftPanel);
        btnSelectImage->setObjectName(QString::fromUtf8("btnSelectImage"));
        btnSelectImage->setMinimumHeight(40);

        leftLayout->addWidget(btnSelectImage);

        btnProcess = new QPushButton(leftPanel);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));
        btnProcess->setMinimumHeight(40);

        leftLayout->addWidget(btnProcess);

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


        leftLayout->addWidget(groupFilters);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        leftLayout->addItem(verticalSpacer);


        mainLayout->addWidget(leftPanel);

        rightPanel = new QFrame(centralwidget);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        gridImages = new QGridLayout(rightPanel);
        gridImages->setObjectName(QString::fromUtf8("gridImages"));
        boxOriginal = new QGroupBox(rightPanel);
        boxOriginal->setObjectName(QString::fromUtf8("boxOriginal"));
        vboxLayout = new QVBoxLayout(boxOriginal);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        lblOriginal = new QLabel(boxOriginal);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setMinimumSize(QSize(350, 250));
        lblOriginal->setScaledContents(true);

        vboxLayout->addWidget(lblOriginal);


        gridImages->addWidget(boxOriginal, 0, 0, 1, 1);

        boxPre = new QGroupBox(rightPanel);
        boxPre->setObjectName(QString::fromUtf8("boxPre"));
        vboxLayout1 = new QVBoxLayout(boxPre);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lblPre = new QLabel(boxPre);
        lblPre->setObjectName(QString::fromUtf8("lblPre"));
        lblPre->setMinimumSize(QSize(350, 250));
        lblPre->setScaledContents(true);

        vboxLayout1->addWidget(lblPre);


        gridImages->addWidget(boxPre, 0, 1, 1, 1);

        boxLungs = new QGroupBox(rightPanel);
        boxLungs->setObjectName(QString::fromUtf8("boxLungs"));
        vboxLayout2 = new QVBoxLayout(boxLungs);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblLungs = new QLabel(boxLungs);
        lblLungs->setObjectName(QString::fromUtf8("lblLungs"));

        vboxLayout2->addWidget(lblLungs);


        gridImages->addWidget(boxLungs, 1, 0, 1, 1);

        boxHeart = new QGroupBox(rightPanel);
        boxHeart->setObjectName(QString::fromUtf8("boxHeart"));
        vboxLayout3 = new QVBoxLayout(boxHeart);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        lblHeart = new QLabel(boxHeart);
        lblHeart->setObjectName(QString::fromUtf8("lblHeart"));

        vboxLayout3->addWidget(lblHeart);


        gridImages->addWidget(boxHeart, 1, 1, 1, 1);

        boxBones = new QGroupBox(rightPanel);
        boxBones->setObjectName(QString::fromUtf8("boxBones"));
        vboxLayout4 = new QVBoxLayout(boxBones);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        lblBones = new QLabel(boxBones);
        lblBones->setObjectName(QString::fromUtf8("lblBones"));

        vboxLayout4->addWidget(lblBones);


        gridImages->addWidget(boxBones, 2, 0, 1, 1);

        boxFinal = new QGroupBox(rightPanel);
        boxFinal->setObjectName(QString::fromUtf8("boxFinal"));
        vboxLayout5 = new QVBoxLayout(boxFinal);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        lblFinal = new QLabel(boxFinal);
        lblFinal->setObjectName(QString::fromUtf8("lblFinal"));

        vboxLayout5->addWidget(lblFinal);


        gridImages->addWidget(boxFinal, 2, 1, 1, 1);


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
        btnSelectImage->setText(QCoreApplication::translate("MainWindow", " Seleccionar imagen CT ", nullptr));
        btnProcess->setText(QCoreApplication::translate("MainWindow", " Procesar imagen", nullptr));
        groupFilters->setTitle(QCoreApplication::translate("MainWindow", "Filtros de preprocesamiento", nullptr));
        chkDnCNN->setText(QCoreApplication::translate("MainWindow", "Filtro Deep Learning DN-CNN (ONNX)", nullptr));
        chkGaussian->setText(QCoreApplication::translate("MainWindow", "Gaussian Blur", nullptr));
        chkCLAHE->setText(QCoreApplication::translate("MainWindow", "CLAHE", nullptr));
        chkEqualize->setText(QCoreApplication::translate("MainWindow", "Equalize Histograma", nullptr));
        chkSobel->setText(QCoreApplication::translate("MainWindow", "Sobel (bordes)", nullptr));
        chkCanny->setText(QCoreApplication::translate("MainWindow", "Canny (bordes)", nullptr));
        chkDeepFGS->setText(QCoreApplication::translate("MainWindow", "Filtro Profundo FGS (t\303\251cnica avanzada)", nullptr));
        boxOriginal->setTitle(QCoreApplication::translate("MainWindow", "Imagen Original", nullptr));
        lblOriginal->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color:#222; border:1px solid #555;", nullptr));
        boxPre->setTitle(QCoreApplication::translate("MainWindow", "Preprocesamiento", nullptr));
        lblPre->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color:#222; border:1px solid #555;", nullptr));
        boxLungs->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n - Pulmones", nullptr));
        boxHeart->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n - Coraz\303\263n", nullptr));
        boxBones->setTitle(QCoreApplication::translate("MainWindow", "Segmentaci\303\263n - Huesos", nullptr));
        boxFinal->setTitle(QCoreApplication::translate("MainWindow", "Imagen Final Resaltada", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
