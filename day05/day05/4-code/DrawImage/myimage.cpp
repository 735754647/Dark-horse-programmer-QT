#include "myimage.h"
#include <QPainter>
#include <QDebug>
#include <QThread>

MyImage::MyImage(QObject *parent) : QObject(parent)
{

}

void MyImage::DrawMyImage()
{
    QImage image(600, 600, QImage::Format_ARGB32);
    QPainter p(&image); // 指定绘图设备
    QPoint points[6] =
    {
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500),
        QPoint(qrand()%500, qrand()%500)
    };
    p.setPen(QPen(Qt::green, 10));
    p.setBrush(Qt::blue);
    p.drawPolygon(points, 6);
    image.save("d:\\myimage.png");
    emit sigImageDone(image);
    qDebug() << QThread::currentThread();
}
