#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setName(QString name);

public slots:
    void onRet();
    void onLogin(QString name);//有主界面 跳转到 登录界面
signals:
    void sigShowLogin();

private:
    Ui::MainWindow *ui;
    QString name;
};

#endif // MAINWINDOW_H
