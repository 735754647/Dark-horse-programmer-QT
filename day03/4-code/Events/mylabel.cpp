#include "mylabel.h"
#include <QMouseEvent>
#include <QTimerEvent>
#include <QTimer>

// QWidget 默认是不追踪鼠标事件的
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置窗口追踪鼠标键
    this->setMouseTracking(true);

    // 启动定时器
    // 参数 1: 触发定时器的时间, 单位: ms
    // 参数2: 使用默认值
    // 返回值: 定时器ID
    id = startTimer(2000);
    id1 = startTimer(3000);


    // 第二种定时器用法
//    QTimer * timer = new QTimer(this);
//    timer->start(100);
//    connect(timer, &QTimer::timeout, this, [=]()
//    {
//        static int number = 0;
//        this->setText(QString::number(number++));
//    });

}

// 进入还是离开边界的一瞬间来完成的
// 鼠标进入
void MyLabel::enterEvent(QEvent *)
{
    setText("你不要在我身上乱摸!!!!");
}

// 鼠标离开
void MyLabel::leaveEvent(QEvent *)
{
    setText("终于离开了...");
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 字符串拼接 QString().arg()
    // %1, %2, %3 -- 占位符
    QString btn;
    if(ev->button() == Qt::LeftButton)
    {
        btn = "LeftButton";
    }
    else if(ev->button() == Qt::RightButton)
    {
        btn = "RightButton";
    }
    else if(ev->button() == Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString("MousePree[%3]:(%1, %2)").arg(ev->x()).arg(ev->y()).arg(btn);

    setText(str);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString btn;
    if(ev->button() == Qt::LeftButton)
    {
        btn = "LeftButton";
    }
    else if(ev->button() == Qt::RightButton)
    {
        btn = "RightButton";
    }
    else if(ev->button() == Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString("MouseRelease[%3]:(%1, %2)").arg(ev->x()).arg(ev->y()).arg(btn);

    setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString btn;
    if(ev->buttons() & (Qt::LeftButton | Qt::RightButton))
    {
        btn = "LeftButton";
    }
    else if(ev->buttons() & Qt::RightButton)
    {
        btn = "RightButton";
    }
    else if(ev->buttons() & Qt::MidButton)
    {
        btn = "MidButton";
    }
    QString str = QString("MouseMove[%3]:(%1, %2)").arg(ev->x()).arg(ev->y()).arg(btn);

    setText(str);
}

// 每触发一次定时器, 进入该函数中
void MyLabel::timerEvent(QTimerEvent *e)
{
    QString str;
    if(e->timerId() == id)
    {
        static int num = -100;
        str = QString("%1: %2").arg("Time out: ").arg(num++);
        if(num >= 100)
        {
            // 关闭定时器
            killTimer(id);
        }

    }
    else if(e->timerId() == id1)
    {
        static int num1 = 10000;
        str = QString("%1: %2").arg("Time out: ").arg(num1++);
        if(num1 >= 10000+1000)
        {
            // 关闭定时器
            killTimer(id1);
        }
    }


    setText(str);
}

