#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "curl/curl.h"
#include "curl/easy.h"
#include <curl/curlver.h>
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
    QString code = ui->lineEdit->text().toUpper();
    if(code.length() == 4){
        ui->lineEdit->setText("");
       printReport(code);
       qDebug() << code;

    }

}

void MainWindow::on_lineEdit_returnPressed()
{

    on_pushButton_clicked();
}

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

void MainWindow::printReport(QString city)
{
     if(city.length() == 0)
     {
         return;
     }
     CURL *curl_handle = nullptr;
     CURLcode res;

     struct MemoryStruct chunk;

     chunk.memory = (char*)malloc(1);  /* will be grown as needed by the realloc above */
     chunk.size = 0;    /* no data at this point */

     curl_global_init(CURL_GLOBAL_ALL);

     /* init the curl session */
       curl_handle = curl_easy_init();
     ostringstream os;
     os << "http://tgftp.nws.noaa.gov/data/observations/metar/decoded/" << city.toStdString() << ".TXT";
     string s =os.str();
     cout << s;

     /* specify URL to get */
     curl_easy_setopt(curl_handle, CURLOPT_URL, s.c_str());

     /* send all data to this function  */
     curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

     /* we pass our 'chunk' struct to the callback function */
     curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

     /* some servers don't like requests that are made without a user-agent
        field, so we provide one */
     curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

     /* get it! */
     res = curl_easy_perform(curl_handle);

     /* check for errors */
     if(res != CURLE_OK) {
       fprintf(stderr, "curl_easy_perform() failed: %s\n",
               curl_easy_strerror(res));
     }
     else {
       /*
        * Now, our chunk.memory points to a memory block that is chunk.size
        * bytes big and contains the remote file.
        *
        * Do something nice with it!
        */

       printf("%lu bytes retrieved\n", (long)chunk.size);
     }

     /* cleanup curl stuff */
     curl_easy_cleanup(curl_handle);
   //  curl_handle.

     qDebug() << chunk.memory;
     QString weather(chunk.memory);

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


     free(chunk.memory);

     /* we're done with libcurl, so clean it up */
     curl_global_cleanup();


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
