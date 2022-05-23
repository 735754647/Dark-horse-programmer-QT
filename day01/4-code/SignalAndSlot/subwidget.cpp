#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    b1= new QPushButton("中腾", this);
    b1->resize(100, 100);

    setWindowTitle("软件园窗口");

    resize(400, 600);

    connect(b1, &QPushButton::clicked, this, &SubWidget::myslot);
}

void SubWidget::myslot()
{
    // 发送信号
    emit sigSub();
    emit sigSub(250, "你是二百五!!!");
}

