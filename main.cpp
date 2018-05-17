#include "mainwindow.h"
#include <QApplication>
#include "QProcess"
#include <wiringPi.h>
#include "buttonconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    wiringPiSetup();
    pinMode(9, INPUT);
    pullUpDnControl(9, PUD_UP);
    wiringPiISR(9, INT_EDGE_FALLING, void button(void) {MainWindow::printReport("KORD");});

    return a.exec();
}
