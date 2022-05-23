#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT    // 如果使用信号和槽, 必须添加这个宏

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    QPushButton b1;
    QPushButton *b2;
};

#endif // MYWIDGET_H
