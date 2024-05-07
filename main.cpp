#include "mainwindow.h"
#include <hfontawesome.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HFontAwesome::initialize();

    MainWindow w;
    w.show();
    return a.exec();
}
