#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);


signals:
    // 自定义信号, 必须使用signals 声明
    void sigSub();
    void sigSub(int , QString);
    /*
     * 1. 可以有参数
     * 2. 可以重载
     * 3. 返回值为void
     * 4. 发送信号: emit + 信号名;
     * emit sigsub();
    */

public slots:
    void myslot();

private:
    QPushButton* b1;
};

#endif // SUBWIDGET_H
