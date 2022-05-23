#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pImage = new MyImage;
    pthred = new QThread(this);

    pImage->moveToThread(pthred);
    pthred->start();

    connect(ui->pushButton, &QPushButton::clicked, pImage, &MyImage::DrawMyImage);
    connect(pImage, &MyImage::sigImageDone, this, &Widget::slotUpdate);
    connect(this, &Widget::destroyed, this, [=]()
    {
        pthred->quit();
        pthred->wait();

        delete pImage;
    });

    qDebug() << QThread::currentThread() << "main";
}

void Widget::slotUpdate(QImage img)
{
    image = img;
    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(50, 50, image);
}

Widget::~Widget()
{
    delete ui;
    //delete pImage;
}
