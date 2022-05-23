#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myimage.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void slotUpdate(QImage img);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    QThread* pthred;
    MyImage* pImage;
    QImage image;
};

#endif // WIDGET_H
