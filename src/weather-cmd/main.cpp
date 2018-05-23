#include <QCoreApplication>
#include "curl/curl.h"
#include "curl/easy.h"
#include <curl/curlver.h>
#include <ostream>
#include <sstream>
#include <iostream>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
#ifdef Q_PROCESSOR_ARM
#include <wiringPi.h>
#endif
#include <qpainter.h>
#include <QCommandLineParser>
#include "metarfetcher.h"


using namespace std;
QStringList cities;

void printReport(int position) {
    /*
    if(city.length() == 0)
    {
        return;
    }
    */
    QString weather = getReport(cities[position]);

#ifdef Q_PROCESSOR_ARM

    QPrinter printer;
    //printer.setOutputFileName("weather");
    QPainter painter;
    painter.begin(&printer);

    QFont font = painter.font();
    font.setPixelSize(12);
    painter.setFont(font);
    const QRect rectangle = QRect(0, 0, 250, 600);
    QRect boundingRect;
    //if(printer.printerState() == 0) {
    painter.drawText(rectangle, Qt::TextWordWrap, weather, &boundingRect);
    painter.end();
    //}
#endif
}

static void button1() {
    printReport(0);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_PROCESSOR_ARM
    wiringPiSetup();
    wiringPiISR(9, INT_EDGE_FALLING, &button1);
    pinMode(9, INPUT);
    pullUpDnControl(9, PUD_UP);
#endif
    QCommandLineParser parser;
    parser.setApplicationDescription("Command-line weather printer");
    parser.addHelpOption();
    parser.addPositionalArgument("cityList", QCoreApplication::translate("main", "ICAO code to print report for"));
    parser.process(a);
    cities = parser.positionalArguments();
#ifdef Q_PROCESSOR_X86
    for(int i=0; i<cities.length(); i++) {
        printReport(i);
    }
    exit(0);
#endif
    return a.exec();
}

