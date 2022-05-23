#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    /*
     *  1. 回调函数
     *  2. 此函数不需要用户与调用, 再刷新的时候会自定调用
     *      1. 窗口显示的时候
     *      2. 最大化, 最小化
     *      3. 窗口被这遮挡, 重新显示的时候
     *      4. 用户强制刷新的时候
     *      5. ...........
     *  3. 如果想使用画家类在窗口中画图, 操作必须在paintEvent函数中完成
    */
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    int x;
};

#endif // WIDGET_H
