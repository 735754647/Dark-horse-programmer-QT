#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用QPixmap画图
    QPixmap pixmap(300, 300);
    pixmap.fill();
    QPainter p;
    p.begin(&pixmap);
    p.setPen(QPen(Qt::red, 5));
    p.drawRect(10, 10, 280, 280);
    p.drawEllipse(QPoint(150, 150), 50, 50);
    p.end();
    pixmap.save("d:\\mypixmap.png");

    // 使用QImage 画图
    QImage image(300, 300, QImage::Format_RGB32);
    image.fill(Qt::yellow);
    p.begin(&image);
    p.setPen(QPen(Qt::blue, 5));
    p.drawRect(10, 10, 280, 280);
    p.drawEllipse(QPoint(150, 150), 50, 50);
    p.end();
    image.save("d:\\myimage.png");

    // 使用QPicture 画图
    QPicture pic;
    p.begin(&pic);
    p.setPen(QPen(Qt::blue, 5));
    p.drawRect(10, 10, 280, 280);
    p.drawEllipse(QPoint(150, 150), 50, 50);
    p.end();
    pic.save("d:\\mypic.pic");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPicture pic;
    pic.load("D:\\mypic.pic");
    p.drawPicture(10, 10, pic);
}
