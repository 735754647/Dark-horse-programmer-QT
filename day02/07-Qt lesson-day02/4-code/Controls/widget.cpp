#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->radioButton, &QRadioButton::released, this, [=]()
    {
        QMessageBox::information(this, "radiobutton", "haha+++");
    });

    connect(ui->checkBox, &QCheckBox::stateChanged, this, [=](int state)
    {
        //QMessageBox::information(this, "checkbox", QString::number(state));
        qDebug() << state;
    });

    ui->listWidget->addItem("hello, 软件园!");
    QListWidgetItem* item = new QListWidgetItem(QIcon("D:\\Luffy.png"), "Luffy", ui->listWidget);
    ui->listWidget->addItem(new QListWidgetItem(QIcon("D:\\Luffy.png"), "luffy"));

    // 1. 指定行数
    ui->tableWidget->setRowCount(100);
    // 2. 指定列数
    ui->tableWidget->setColumnCount(3);
    QStringList list;
    list << "姓名" << "性别" << "年龄";
    ui->tableWidget->setHorizontalHeaderLabels(list);

    connect(ui->btnMusic, &QPushButton::clicked, this, [=]()
    {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnVideo, &QPushButton::clicked, this, [=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->video);
    });
    connect(ui->btnOther, &QPushButton::clicked, this, [=]()
    {
        ui->stackedWidget->setCurrentIndex(2);
    });

    //ui->image->setPixmap(QPixmap(":/Image/Luffy.png"));
    QMovie* movie = new QMovie(":/Image/mario.gif");
    ui->image->setMovie(movie);
    movie->start(); // 启动播放
}

Widget::~Widget()
{
    delete ui;
}
