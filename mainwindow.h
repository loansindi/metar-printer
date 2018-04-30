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



private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void printReport(QString city);

    void on_pushButton_KORD_clicked();

    void on_pushButton_KMDW_clicked();

    void on_pushButton_KJFK_clicked();

    void on_pushButton_KGUS_clicked();

    void on_pushButton_KMSP_clicked();

    void on_pushButton_KCMX_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
