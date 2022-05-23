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
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::Widget *ui;
    QPixmap pix;

    // 两张图
    QPixmap up;
    QPixmap down;
    QPoint pt;  // 差值
};

#endif // WIDGET_H
