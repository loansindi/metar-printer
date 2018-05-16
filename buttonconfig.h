#ifndef BUTTONCONFIG_H
#define BUTTONCONFIG_H

#include <QDialog>

namespace Ui {
class buttonConfig;
}

class buttonConfig : public QDialog
{
    Q_OBJECT

public:
    explicit buttonConfig(QWidget *parent = 0);
    ~buttonConfig();
    //QString optionOne();
signals:
    QString configAccepted(QString, QString, QString, QString, QString, QString);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::buttonConfig *ui;
};

#endif // BUTTONCONFIG_H
