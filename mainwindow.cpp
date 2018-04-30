#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "curl/curl.h"
#include "curl/easy.h"
#include <curl/curlver.h>
#include "iostream"

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
    QString code = ui->lineEdit->text();
    ui->lineEdit->setText("");
    printReport(code);
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString code = ui->lineEdit->text();
    ui->lineEdit->setText("");
    printReport(code);
}


void MainWindow::printReport(QString city)
{

    QStringList arguments;
    QProcess *metarset = new QProcess();
    metarset->start("/usr/bin/metar", QStringList() << "set" << city);
    metarset->waitForFinished();
    metarset->close();
    QProcess *metarget = new QProcess();
    metarget->start("metar get");
    metarget->waitForFinished();
    QString response = metarget->readAllStandardOutput();
    //std::cout << response.toStdString();
    metarget->close();
    //qInfo(response.toStdString().c_str());
    QProcess *process = new QProcess();
    process->start("/usr/bin/lp -o cpi=20 -");
    process->write(response.toStdString().c_str());
    process->closeWriteChannel();
}


void MainWindow::on_pushButton_KORD_clicked()
{
    printReport("KORD");
}

void MainWindow::on_pushButton_KMDW_clicked()
{
    printReport("KMDW");
}

void MainWindow::on_pushButton_KJFK_clicked()
{
    printReport("KJFK");
}

void MainWindow::on_pushButton_KGUS_clicked()
{
    printReport("KGUS");
}

void MainWindow::on_pushButton_KMSP_clicked()
{
    printReport("KMSP");
}

void MainWindow::on_pushButton_KCMX_clicked()
{
    printReport("KCMX");
}
