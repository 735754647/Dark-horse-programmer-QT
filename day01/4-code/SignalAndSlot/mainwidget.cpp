#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // init
    b1 = new QPushButton("老大", this);
    b1->move(100, 100);

    b2 = new QPushButton;
    b2->setParent(this);
    b2->setText("老二");
    b2->move(200, 200);

    // b1 close window
    // qt 信号和槽他们都是函数
    // 1. 信号只有函数声明, 不需要函数定义
    // 2. 槽函数据需要声明也需要定义, 回调函数
    // connect(b1, &QPushButton::pressed, this, &MainWidget::close);

    // 自定义槽函数
    /*
     * 1. 槽函数在Qt5 可以是任意类成员函数, 全局函数, 静态函数, lambda表达式(隐式函数)
     * 2. 槽函数需要与信号对相应(返回值, 参数)
     * 3. 信号没有返回值, 槽函数返回值: void
     * 4. void mysig(int, double, QString);
     *    void myslot(int, double);
     * 5. 槽函数的参数是为了接受信号传过来的的数据
     * 6. 槽函数的参数应该是不能够大于信号的参数个数, 可以少于信号的参数个数
     * 7. 槽函数可以重载
    */

    connect(b1, &QPushButton::released, this, &MainWidget::slotForMianWidget);


    // b3 显示子窗口SubWidget  -- subW
    b3 = new QPushButton("软件园", this);
    b3->resize(100, 50);
    b3->move(200, 200);

    connect(b3, &QPushButton::clicked, this, &MainWidget::slotHideMe);

    // Qt 5 信号槽的使用方法
    void (SubWidget::*MySigSub)() = &SubWidget::sigSub;
    connect(&subW, MySigSub, this, &MainWidget::slotShowMe);

    void (SubWidget::*MysigPlus)(int, QString) = &SubWidget::sigSub;
    connect(&subW, MysigPlus, this, &MainWidget::slotSubMsg);

    // Q4 信号槽
    // SIGNAL() SLOT() 宏 将函数转换为字符串
//    connect(&subW, SIGNAL(sigSub()), this, SLOT(slotShowMe()));
//    connect(&subW, SIGNAL(sigSub(int , QString)), this, SLOT(ABCDe(bb, aa)));

    // 使用lambda表达式作为槽函数
    connect(b1, &QPushButton::clicked, this, [=]()
    {
        b2->setText("lambda表达式!!!");
        b3->hide();
    });
}

MainWidget::~MainWidget()
{

}

void MainWidget::slotForMianWidget()
{
    b2->setText("我被老大改名了...");
}

void MainWidget::slotHideMe()
{
    // 隐藏自己
    hide();
    // 显示软件园窗口
    subW.show();
}

void MainWidget::slotShowMe()
{
    // 显示自己
    show();
    // 隐藏软件园窗口
    subW.hide();
}

void MainWidget::slotSubMsg(int num, QString str)
{
    // QString --> char*
    // string --> char*   .data()
    qDebug() << num << str.toUtf8().data();

}
