#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 加载图片
    pix.load("D:\\sunny.png");
    // 去掉边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    // 设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    // 加载图片
    // 定时器 设置时间间隔
    // QTimer
    // connect(timer, timeout, [=](){ 刷新窗口 });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    // 在窗口中将图片画出来
    QPainter p(this);
    p.drawPixmap(0, 0, pix);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        // 求差值 左键按下的点 - 窗口坐上角的点坐标
        pt = e->globalPos() - this->frameGeometry().topLeft();
    }
    else if(e->button() == Qt::RightButton)
    {
        // close windows
        this->close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    // mvoe x , y 使用的屏幕坐标系
    // e->x() , e->y() 窗口的坐标系 Widget
    this->move(e->globalPos() - pt);
}
