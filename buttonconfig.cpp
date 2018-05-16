#include "buttonconfig.h"
#include "ui_buttonconfig.h"
#include "mainwindow.h"
#include "QDebug"


buttonConfig::buttonConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buttonConfig)
{
    ui->setupUi(this);
}

buttonConfig::~buttonConfig()
{
    delete ui;
}


void buttonConfig::on_buttonBox_accepted()
{
    qDebug() << ui->lineEdit_1->text();
    emit(configAccepted(ui->lineEdit_1->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(), ui->lineEdit_6->text()));
}
