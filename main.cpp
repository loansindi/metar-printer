#include "mainwindow.h"
#include <QApplication>
#include "QProcess"
#include <wiringPi.h>
#include "buttonconfig.h"



MainWindow* w;
static void button()
{
    w->printReport("KORD");
}
int main(int argc, char *argv[])
{
    w = new MainWindow(&a);
    QApplication a(argc, argv);
    w.show();


    wiringPiISR(9, INT_EDGE_FALLING, button);
    wiringPiSetup();
    pinMode(9, INPUT);
    pullUpDnControl(9, PUD_UP);

    return a.exec();

}

