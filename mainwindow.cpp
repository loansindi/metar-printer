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

    //QString city = ui->plainTextEdit->toPlainText();
    QStringList arguments;
    arguments << ui->plainTextEdit->toPlainText();

    QProcess *metarset = new QProcess();
    metarset->start("metar set", arguments);
    metarset->waitForFinished();
    metarset->close();
    QProcess *metarget = new QProcess();
    metarget->start("metar get");
    metarget->waitForFinished();
    QString response = metarget->readAllStandardOutput();
    std::cout << response.toStdString();
    metarget->close();
    //qInfo(response.toStdString().c_str());
    QProcess *process = new QProcess();
    process->start("/usr/bin/lp -");
    process->write(response.toStdString().c_str());
    process->closeWriteChannel();
}
