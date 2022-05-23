#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include "mywork.h"
#include <QThread>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    // 开始按钮
    void slotStart();
    // 关闭按钮
    void slotStop();
    // 定时器
    void slotTimeout();
    // 关闭线程
    void slotCloseThread();

signals:
    void sigWorking();

private:
    Ui::MyWidget *ui;
    QTimer* mytimer;
    MyWork *work;
    QThread* pthread;
};

#endif // MYWIDGET_H
