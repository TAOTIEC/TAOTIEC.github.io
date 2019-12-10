#include "mydatabase.h"
#include <QDebug>

MyDatabase::MyDatabase(QObject *parent): QObject(parent)
{
    init();
}

void MyDatabase::init()//连接数据库，创建关系表
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Test.db");
    bool ok = db.open();
    if (!ok)
    {
        qDebug() << "open db error: " << db.lastError().text();
        throw db.lastError().text();
    }
    //-----连接数据库完成
    QSqlQuery query;
    ok = query.exec("create table if not exists Tab_user(id int primary key, name next unique not null, pwd text not null);");
    if (!ok)
    {
        qDebug() << "create table error: " << query.lastError().text();
        throw query.lastError().text();
    }
    //-----创建关系表完成
}

//根据name,pwd查询后, 登录
bool MyDatabase::MyLogin(QString name, QString pwd)
{
    QString sql = "select name, pwd from Tab_user where name='"+name+"' and "+"pwd='"+pwd +"';";
    qDebug() << "sql: " << sql;

    QSqlQuery query;
    bool ok = query.exec(sql);
    if (!ok)
    {
        qDebug() << "don`t have element" << query.lastError().text();
        return false;
    }
    while(query.next())
    {
        return true;
        qDebug() << "-------select ok-----";
    }
    return false;
}

//注册界面 注册(增加)操作
bool MyDatabase::MyRegister(int id, QString name, QString pwd)
{
    QString sql = QString("insert into Tab_user values(%1, '%2', '%3')").arg(id).arg(name).arg(pwd);
    QSqlQuery query;
    bool ok = query.exec(sql);
    if (!ok)
    {
        qDebug() << "insert error:" << query.lastError();
        return false;
    }
    else
    {
        qDebug() << "sql:" << sql;
        return true;
    }
    return false;
}

//忘记密码(删除) 登录界面 输入框里面显示的成员
bool MyDatabase::MyForget(QString name, QString pwd)
{
    QString sql = "delete from tab_user where 'name'='name' and 'pwd'='pwd'";
    QSqlQuery query;
    bool ok = query.exec(sql);
    if (!ok)
    {
        qDebug() << "delete error: " << query.lastError();
        return false;
    }
    else
    {
        qDebug() << "sql: " << sql;
        return true;
    }
    return false;
}


