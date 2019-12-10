#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QSqlError>

class MyDatabase:public QObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = nullptr);
    void init();
    bool MyLogin(QString name, QString pwd);
    bool MyRegister(int id, QString name, QString pwd);
    bool MyForget(QString name, QString pwd);

};


#endif // MYDATABASE_H
