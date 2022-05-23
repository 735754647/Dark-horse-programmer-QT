#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

signals:

public slots:

protected:
    // 鼠标进入
    void enterEvent(QEvent *);
    // 鼠标离开
    void leaveEvent(QEvent *);
    // 鼠标按下
    void mousePressEvent(QMouseEvent *ev);
    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev);
//    // 鼠标移动
    void mouseMoveEvent(QMouseEvent *ev);
//    // 定时器
    void timerEvent(QTimerEvent *);

private:
    int id;
    int id1;
};

#endif // MYLABEL_H
