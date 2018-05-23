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
    emit(configAccepted(ui->lineEdit_1->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(), ui->lineEdit_6->text()));
}

void buttonConfig::receiveButtons(QString one, QString two, QString three, QString four, QString five, QString six)
{
    ui->lineEdit_1->setText(one);
    ui->lineEdit_2->setText(two);
    ui->lineEdit_3->setText(three);
    ui->lineEdit_4->setText(four);
    ui->lineEdit_5->setText(five);
    ui->lineEdit_6->setText(six);
}
