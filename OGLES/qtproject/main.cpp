#include "mainwindow.h"
#include <QApplication>

#define QtProject

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setTitle("App running on QT now...");
    w.resize(960,540);
    w.show();

    return a.exec();
}
