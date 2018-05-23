#include "mainwindow.h"
#include "buttonconfig.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <stdlib.h>
#include <QDebug>
#include <string>
#include <sstream>
#include <ostream>
#include <QtPrintSupport/QPrinter>
#include <qpainter.h>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport>
#include "metarfetcher.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    statusBar()->showMessage("");
    QString code = ui->lineEdit->text().toUpper();
    if(code.length() == 4){
        ui->lineEdit->setText("");
       printReport(code);
       qDebug() << code;

    }
    else{
        statusBar()->showMessage("Please enter a four letter ICAO code");
        ui->lineEdit->setText("");
    }

}

void MainWindow::on_lineEdit_returnPressed()
{

    on_pushButton_clicked();
}

void MainWindow::printReport(QString city)
{
    QString weather = getReport(city);
   //  curl_handle.
     if( weather != "") {
         statusBar()->showMessage("Printing report for " + city);


         qDebug() << weather;

         QPrinter printer;
         //printer.setOutputFileName("weather");
         QPainter painter;
         painter.begin(&printer);

         QFont font = painter.font();
         font.setPixelSize(ui->fontSize->text().toInt());
         painter.setFont(font);
         const QRect rectangle = QRect(0, 0, 250, 600);
         QRect boundingRect;
         painter.drawText(rectangle, Qt::TextWordWrap, weather, &boundingRect);
         painter.end();
     }
     else {
         statusBar()->showMessage("Invalid Airport code or other error");
     }
}


void MainWindow::on_pushButton_1_clicked()
{
    printReport(ui->pushButton_1->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    printReport(ui->pushButton_2->text());
}

void MainWindow::on_pushButton_3_clicked()
{
    printReport(ui->pushButton_3->text());
}

void MainWindow::on_pushButton_4_clicked()
{
    printReport(ui->pushButton_4->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    printReport(ui->pushButton_5->text());
}

void MainWindow::on_pushButton_6_clicked()
{
    printReport(ui->pushButton_6->text());
}

void MainWindow::on_actionSet_Buttons_triggered()
{
    buttonConfig *buttons = new buttonConfig(this);
    connect(buttons, SIGNAL(configAccepted(QString,QString,QString,QString,QString,QString)), this, SLOT(setButtons(QString,QString,QString,QString,QString,QString)));
    connect(this, SIGNAL(sendButtons(QString, QString, QString, QString, QString, QString)), buttons, SLOT(receiveButtons(QString,QString,QString,QString,QString,QString)));
    emit(sendButtons(ui->pushButton_1->text(), ui->pushButton_2->text(), ui->pushButton_3->text(), ui->pushButton_4->text(), ui->pushButton_5->text(), ui->pushButton_6->text()));
    buttons->exec();
}

void MainWindow::setButtons(QString one, QString two, QString three, QString four, QString five, QString six) {
    ui->pushButton_1->setText(one.toUpper());
    ui->pushButton_2->setText(two.toUpper());
    ui->pushButton_3->setText(three.toUpper());
    ui->pushButton_4->setText(four.toUpper());
    ui->pushButton_5->setText(five.toUpper());
    ui->pushButton_6->setText(six.toUpper());
}
