#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_begin_clicked();

private:
    Ui::MyWidget *ui;
    QTimer* mytimer;
    MyThread *myt;
};

#endif // MYWIDGET_H
