#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    // 自定义槽函数
    void slotForMianWidget();
    void slotHideMe();
    void slotShowMe();
    void slotSubMsg(int num, QString str);

private:
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;    // 显示子窗口
    // 子窗口对象
    SubWidget subW;

};

#endif // MAINWIDGET_H
