#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 寻找QAction 对象
    connect(ui->actionOpen, &QAction::triggered, this, [=]()
    {
        QString fileName = QFileDialog::getOpenFileName(this, "打开", "D:\\");
        qDebug() << fileName.toUtf8().data();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
