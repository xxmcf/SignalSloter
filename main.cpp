#include "mainwindow.h"
#include <QApplication>

void myobject_test();

int main(int argc, char *argv[])
{

    myobject_test();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
