#include <QApplication>

#include "mainwindow.h"

using namespace HLDemo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
