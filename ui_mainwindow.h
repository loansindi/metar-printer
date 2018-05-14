/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QDoubleSpinBox *fontSize;
    QGridLayout *gridLayout;
    QPushButton *pushButton_KMDW;
    QPushButton *pushButton_KMSP;
    QPushButton *pushButton_KORD;
    QPushButton *pushButton_KJFK;
    QPushButton *pushButton_KGUS;
    QPushButton *pushButton_KCMX;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(612, 335);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 611, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        fontSize = new QDoubleSpinBox(horizontalLayoutWidget);
        fontSize->setObjectName(QStringLiteral("fontSize"));
        fontSize->setDecimals(0);
        fontSize->setMinimum(6);
        fontSize->setMaximum(20);
        fontSize->setValue(10);

        verticalLayout->addWidget(fontSize);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        pushButton_KMDW = new QPushButton(horizontalLayoutWidget);
        pushButton_KMDW->setObjectName(QStringLiteral("pushButton_KMDW"));

        gridLayout->addWidget(pushButton_KMDW, 0, 2, 1, 1);

        pushButton_KMSP = new QPushButton(horizontalLayoutWidget);
        pushButton_KMSP->setObjectName(QStringLiteral("pushButton_KMSP"));

        gridLayout->addWidget(pushButton_KMSP, 1, 2, 1, 1);

        pushButton_KORD = new QPushButton(horizontalLayoutWidget);
        pushButton_KORD->setObjectName(QStringLiteral("pushButton_KORD"));

        gridLayout->addWidget(pushButton_KORD, 0, 1, 1, 1);

        pushButton_KJFK = new QPushButton(horizontalLayoutWidget);
        pushButton_KJFK->setObjectName(QStringLiteral("pushButton_KJFK"));

        gridLayout->addWidget(pushButton_KJFK, 0, 3, 1, 1);

        pushButton_KGUS = new QPushButton(horizontalLayoutWidget);
        pushButton_KGUS->setObjectName(QStringLiteral("pushButton_KGUS"));

        gridLayout->addWidget(pushButton_KGUS, 1, 1, 1, 1);

        pushButton_KCMX = new QPushButton(horizontalLayoutWidget);
        pushButton_KCMX->setObjectName(QStringLiteral("pushButton_KCMX"));

        gridLayout->addWidget(pushButton_KCMX, 1, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Enter Airport Identifier", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Print Report", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Font Size", nullptr));
        pushButton_KMDW->setText(QApplication::translate("MainWindow", "KMDW", nullptr));
        pushButton_KMSP->setText(QApplication::translate("MainWindow", "KMSP", nullptr));
        pushButton_KORD->setText(QApplication::translate("MainWindow", "KORD", nullptr));
        pushButton_KJFK->setText(QApplication::translate("MainWindow", "KJFK", nullptr));
        pushButton_KGUS->setText(QApplication::translate("MainWindow", "KGUS", nullptr));
        pushButton_KCMX->setText(QApplication::translate("MainWindow", "KCMX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
