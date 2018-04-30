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
    QString get = "metar set";
    QStringList arguments;

    arguments += code;
    QProcess *metarset = new QProcess();
    metarset->start("/usr/bin/metar", QStringList() << "set" << code);
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

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}
