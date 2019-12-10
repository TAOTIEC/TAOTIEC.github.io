#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mydatabase.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



signals:
    void sigLoginSuccess(QString name);
    void sigRegSuccess(QString name);
    void sigForgetSuccess();

public slots:
    void onCancel();
    void onLogin();
    void onRegister();
    void onForget();

private slots:
    void on_btn_register_clicked();
    void on_btn_onRet_clicked();

private:
    Ui::Widget *ui;
    MyDatabase *db;
};

#endif // WIDGET_H
