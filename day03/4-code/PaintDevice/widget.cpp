#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 在QPixmap中画图
    QPixmap pix(300, 300);  // 纸的大小
    pix.fill(Qt::red);
    QPainter p(&pix);
    p.setPen(QPen(Qt::green, 10));
    p.drawRect(10, 10, 280, 280);
    p.drawEllipse(150, 150, 50, 50);
    pix.save("D:\\mypixmap.png");

    // 指定绘图设备 1. 构造函数中(参数是绘图设备)
    // 2. begin(参数是绘图设备)
     //    end();
     // 在QImage中画图
    QImage img(300, 300, QImage::Format_RGB32);  // 纸的大小
    img.fill(Qt::red);
    p.begin(&img);
    p.setPen(QPen(Qt::green, 10));
    p.drawRect(10, 10, 280, 280);
    p.drawEllipse(150, 150, 50, 50);
    p.end();
    img.save("D:\\myImage.png");

    // 在QPicture中画图
    // 1. 保存的是绘图步骤 -- 画家类
    // 2. 不是图片, 二进制文件(save保存生成的文件)
    // 3. 不依赖平台
   QPicture pic;  // 纸的大小
   p.begin(&pic);
   p.setPen(QPen(Qt::green, 10));
   p.drawRect(10, 10, 280, 280);
   p.drawEllipse(150, 150, 50, 50);
   p.end();
   pic.save("D:\\mypic.aaa");
}

// QWidget
// QPixmap QImage QPicture QBitmap(黑白图片)
// QBitmap 父类 QPixmap
// QPixmap -- 图片类, 主要用来显示, 它针对于显示器显示做了特殊优化, 依赖于平台的, 只能在主线程中使用(UI线程)
// QIamge -- 图片类 , 不依赖有平台, (图片传输 , 可以在多线程中对其进行操作)
Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPicture pic;
    pic.load("D:\\mypic.png");
    p.drawPicture(100, 100, pic);
}
