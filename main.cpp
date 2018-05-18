#include "mainwindow.h"
#include <QApplication>
#include "QProcess"
#include <wiringPi.h>
#include "buttonconfig.h"


MainWindow w;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w.show();


    wiringPiSetup();
    pinMode(9, INPUT);
    pullUpDnControl(9, PUD_UP);

    return a.exec();

}

