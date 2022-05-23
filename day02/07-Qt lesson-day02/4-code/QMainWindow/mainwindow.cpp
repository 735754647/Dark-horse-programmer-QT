#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QDialog>  // 对话框类
#include <QMessageBox>  // 提示对话框
#include <QColorDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    number(10)
{
    ui->setupUi(this);
   // number = 10;
//    ui->menuEdit->addAction();
    connect(ui->actionOpen, &QAction::triggered, this, [=]()
    {
//        QDialog dlg(this);
//        // 显示模态对话框 exec
//        dlg.exec(); // 阻塞


//        QString name = QFileDialog::getOpenFileName(this, "打开文件", "D:\\", "Image (*.jpg *.png)");
//        qDebug() << name.toUtf8().data();

//        if(QMessageBox::Ok == QMessageBox::question(this, "error", "系统文件错误!!!",
//                                                    QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            QDialog dlg(this);
//            // 显示模态对话框 exec
//            dlg.exec(); // 阻塞

//        }

//        QColor color = QColorDialog::getColor();
//        qDebug() << color.red() << color.green() << color.blue();

        bool ok;
        QFont font = QFontDialog::getFont(&ok, QFont("华文彩云"), this, "我的字体设置");
        if(ok)
        {
            qDebug() << font.family().toUtf8().data() << font.italic() << font.pointSize() << font.bold();
        }

    });

    connect(ui->actionSave, &QAction::triggered, this, [=]()
    {
        QDialog *dlg = new QDialog(this);
        // 显示非模态对话框 show()
        // 设置对话框属性
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show(); // 非阻塞


    });



    ui->dockWidget->show();

    QPushButton* button = new QPushButton("hello", this);
    ui->statusBar->addWidget(button);

    QLabel* label = new QLabel("world", this);
    ui->statusBar->addWidget(label);

    // 规则: :+添加的前缀/+文件名
    ui->actionSave_as->setIcon(QIcon(":/new/Image/face.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
