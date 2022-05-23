#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionAas->setIcon(QIcon(":/Image/vutterfly.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
