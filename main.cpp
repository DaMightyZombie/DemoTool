#include "mainwindow.h"
#include "hldemo.h"

#include <stdio.h>
#include <string>

#include <QApplication>

using namespace HLDemo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
