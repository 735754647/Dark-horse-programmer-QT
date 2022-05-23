#ifndef MYTEST_H
#define MYTEST_H

#include <QWidget>

namespace Ui {
class MyTest;
}

class MyTest : public QWidget
{
    Q_OBJECT

public:
    explicit MyTest(QWidget *parent = 0);
    ~MyTest();

private:
    Ui::MyTest *ui;
};

#endif // MYTEST_H
