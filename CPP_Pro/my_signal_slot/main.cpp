#include "widget.h"
#include "mainwindow.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    MainWindow mw;
    QObject::connect(&w, SIGNAL(sigLoginSuccess(QString)), &mw, SLOT(onLogin(QString)));

    return a.exec();
}
