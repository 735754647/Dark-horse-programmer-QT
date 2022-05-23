#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QFont>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    x = 20;
    ui->setupUi(this);

    connect(ui->move, &QPushButton::clicked, this, [=]()
    {
       // 刷新窗口
        update();   // 系统调用paintEvent 函数
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    // 创建画家类对象
    QPainter p(this);   // 指定绘图设备

#if 0
    // 创建新画笔 -- 轮廓
    QPen pen;
    pen.setColor(/*Qt::green*/QColor(0, 255, 0));
    pen.setWidth(10);   // 像素
    pen.setStyle(Qt::DotLine);

    // 闭合区域使用画刷
    QBrush brush(QPixmap(":/Image/face.png"));
    p.setBrush(brush);

    // 将新画笔设置给画家类
    p.setPen(pen);
    // 画背景图
    p.drawPixmap(0, 0, QPixmap(":/Image/xks.png"));

    // 画直线
    p.drawLine(QPoint(100, 100), QPoint(300, 500));

    // 画椭圆
    p.drawEllipse(QPoint(200, 200), 100, 50);

    // 画矩形
    p.drawRect(400, 200, 200, 200);

    // 写字
    QFont font("华文彩云", 48, 75, true);
    p.setFont(font);
    p.drawText(100, 400, "我是中国人, 我爱我的祖国!!!");

    int width = this->width();
    int heght = this->height();
#endif
    // 提供笑脸
    x += 5;
    if(x > this->width())
    {
        x = 20;
    }
    p.drawPixmap(x, 100, QPixmap(":/Image/sunny.png"));

}
