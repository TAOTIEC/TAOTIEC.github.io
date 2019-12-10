#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600, 300);
    connect(ui->btn_ret, SIGNAL(clicked(bool)),
            this, SLOT(onRet()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRet()
{
    //把自己关闭，并显示先前的登录界面
    this->close();
    emit sigShowLogin();
}


void MainWindow::onLogin(QString name)
{
    this->name = name;
    this->setWindowTitle("用户名 "+name);
    this->show();
}

void MainWindow::setName(QString name)
{
    name = name;
    QString text = ui->label_welcome->text();
    text += name;
    ui->label_welcome->setText(text);
}

