#include "mainwindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <hwidget/hfontawesome.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout(this);
    QPushButton *button = new QPushButton(HFontAwesome::icon(fa::fa_regular, fa::fa_diagram_successor), "按钮", this);
    rootLayout->addWidget(button);
}

MainWindow::~MainWindow() {}
