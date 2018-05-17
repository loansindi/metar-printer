#include "mainwindow.h"
#include "buttonconfig.h"
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
#include <wiringPi.h>

using namespace std;
long response_code;


static void button();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiISR(9, INT_EDGE_FALLING, &button);



}



MainWindow::~MainWindow()
{
    delete ui;
}


static void button()
{
    printReport("KORD");
}


void MainWindow::on_pushButton_clicked()
{
    statusBar()->showMessage("");
    QString code = ui->lineEdit->text().toUpper();
    if(code.length() == 4){
        ui->lineEdit->setText("");
       printReport(code);
       qDebug() << code;

    }
    else{
        statusBar()->showMessage("Please enter a four letter ICAO code");
        ui->lineEdit->setText("");
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
         curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
         qDebug() << response_code;

       printf("%lu bytes retrieved\n", (long)chunk.size);
     }

     /* cleanup curl stuff */
     curl_easy_cleanup(curl_handle);
   //  curl_handle.
     if(response_code == 200) {
         statusBar()->showMessage("Printing report for " + city);


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
     }
     else {
         statusBar()->showMessage("Invalid Airport code or other error");
     }


     free(chunk.memory);

     /* we're done with libcurl, so clean it up */
     curl_global_cleanup();


}


void MainWindow::on_pushButton_1_clicked()
{
    printReport(ui->pushButton_1->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    printReport(ui->pushButton_2->text());
}

void MainWindow::on_pushButton_3_clicked()
{
    printReport(ui->pushButton_3->text());
}

void MainWindow::on_pushButton_4_clicked()
{
    printReport(ui->pushButton_4->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    printReport(ui->pushButton_5->text());
}

void MainWindow::on_pushButton_6_clicked()
{
    printReport(ui->pushButton_6->text());
}

void MainWindow::on_actionSet_Buttons_triggered()
{
    buttonConfig *buttons = new buttonConfig(this);
    connect(buttons, SIGNAL(configAccepted(QString,QString,QString,QString,QString,QString)), this, SLOT(setButtons(QString,QString,QString,QString,QString,QString)));
    connect(this, SIGNAL(sendButtons(QString, QString, QString, QString, QString, QString)), buttons, SLOT(receiveButtons(QString,QString,QString,QString,QString,QString)));
    emit(sendButtons(ui->pushButton_1->text(), ui->pushButton_2->text(), ui->pushButton_3->text(), ui->pushButton_4->text(), ui->pushButton_5->text(), ui->pushButton_6->text()));
    buttons->exec();
}

void MainWindow::setButtons(QString one, QString two, QString three, QString four, QString five, QString six) {
    ui->pushButton_1->setText(one.toUpper());
    ui->pushButton_2->setText(two.toUpper());
    ui->pushButton_3->setText(three.toUpper());
    ui->pushButton_4->setText(four.toUpper());
    ui->pushButton_5->setText(five.toUpper());
    ui->pushButton_6->setText(six.toUpper());
}
