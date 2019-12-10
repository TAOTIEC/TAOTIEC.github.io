#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(600, 300);
    //取消按钮的信号 和槽的连接
    connect(ui->btn_onCancel, SIGNAL(clicked(bool)),
            this, SLOT(onCancel()));
    //登录按钮的信号 和槽的连接
    connect(ui->btn_onLogin, SIGNAL(clicked(bool)),
            this, SLOT(onLogin()));
    //保证程序执行时， 首页是登录页面
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    db = new MyDatabase(this);
    //注册按钮的信号 和槽的连接
    connect(ui->btn_onReg, SIGNAL(clicked(bool)),
            this, SLOT(onRegister()));
    //忘记密码按钮的信号 和槽的连接
    connect(ui->btn_forget_pwd, SIGNAL(clicked(bool)),
            this, SLOT(onForget()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onCancel()//取消按钮
{
    //将文本框的内容清空
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();

}

void Widget::onLogin()//登录按钮
{
    //从界面获取用户 输入的信息(所有从界面获取的信息 都是字符串)
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    //判断输入是否合法
    if (!db->MyLogin(username, password))
    {
        QMessageBox::information(this, "登录错误", "用户名错误或密码错误");
        return;
    }
    else
    {
        //如果输入合法， 关闭/隐藏登录界面， 然后显示新界面(主界面)
        this->hide();
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        emit sigLoginSuccess(username);
    }
}


void Widget::on_btn_register_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_register);
}

void Widget::on_btn_onRet_clicked()//
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
}

void Widget::onRegister()//注册界面的 注册按钮
{
    int id_reg = ui->lineEdit_reg_id->text().toInt();
    qDebug() << "id=" << id_reg;
    QString name_reg = ui->lineEdit_reg_name->text();
    QString pwd_reg = ui->lineEdit_reg_pwd->text();
    //判断注册是否合法
    if(!db->MyRegister(id_reg, name_reg, pwd_reg))
    {
        QMessageBox::information(this, "注册错误", "？？？？？");
        return;
    }
    else
    {
        ui->lineEdit_reg_id->clear();
        ui->lineEdit_reg_name->clear();
        ui->lineEdit_reg_pwd->clear();
        emit sigRegSuccess(name_reg);
    }

}

void Widget::onForget()//登录界面的 忘记密码按钮
{
    //通过输入框的name、pwd来 该成员信息，那么输入框可能会没内容。
    QString name_forget = ui->lineEdit_username->text();
    QString pwd_forget = ui->lineEdit_password->text();
    if (!db->MyForget(name_forget, pwd_forget))
    {
        QMessageBox::information(this, "忘记密码失败", "???");
        return;
    }
    else
    {
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        emit sigForgetSuccess();
    }
}




