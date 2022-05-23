#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>


MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
  ,ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    /* 多线程使用注意事项:
     * 1. 业务对象, 构造的时候不能指定父对象
     * 2. 子线程中不能处理ui窗口(ui相关的类)
     * 3. 子线程中只能处理一些数据相关的操作, 不能涉及窗口
    */
    mytimer  = new QTimer(this);
    // 1. 业务对象
    work = new MyWork();
    // 2. 子线程类
    pthread = new QThread(this);
    // 3. 移动业务对象到子线程
    work->moveToThread(pthread);
    // 5. 子线程工作
    connect(this, &MyWidget::sigWorking, work, &MyWork::doMyWork);


    connect(ui->start, &QPushButton::clicked, this, &MyWidget::slotStart);
    connect(ui->stop, &QPushButton::clicked, this, &MyWidget::slotStop);
    // 定时器
    connect(mytimer, &QTimer::timeout, this, &MyWidget::slotTimeout);

    // 窗口析构的时候干掉线程
    connect(this, &MyWidget::destroyed, this, &MyWidget::slotCloseThread);

    qDebug() << QThread::currentThread() << "main thread";

    /* connect 的第 5 参数
     * 1. 自动连接 -- 默认
     *      多线程 -- 指定队列连接
     *      单线程 -- 指定直接连接
     * 2. 队列连接 -- 多线程
     *      槽函数在信号接受者(receiver)所在的线程中执行
     * 3. 直接连接 -- 单线程
     *      信号和槽函数在同一个线程中执行
    */
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::slotStart()
{
    if(mytimer->isActive() == true)
    {
        return;
    }
    if(pthread->isRunning())
    {
        return;
    }
    mytimer->start(500);
    // 4. 启动子线程
    pthread->start();

    // 发信号, 让子线程工作
    emit sigWorking();
}

void MyWidget::slotStop()
{

}

void MyWidget::slotTimeout()
{
    static int num = 0;
    ui->lcdNumber->display(num++);
}

void MyWidget::slotCloseThread()
{
    work->setFlage(true);

    pthread->quit();
    pthread->wait();    // 等待线程手头上的工作处理完成
}
