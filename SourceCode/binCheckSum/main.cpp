#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Check Sum Tool || Authored by magix_xy || 2022/01/15");
    w.show();
    return a.exec();
}
