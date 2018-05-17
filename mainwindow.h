#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QString sendButtons(QString one, QString two, QString three, QString four, QString five, QString six);


signals:
    QString sendButtons(QString, QString, QString, QString, QString, QString);


private slots:
    void button();

    void setButtons(QString one, QString two, QString three, QString four, QString five, QString six);

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void printReport(QString city);

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_actionSet_Buttons_triggered();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
