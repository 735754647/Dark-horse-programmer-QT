#include "mywork.h"
#include <QThread>
#include <QMessageBox>
#include <QDebug>

MyWork::MyWork(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void MyWork::doMyWork()
{
    while(!isStop)
    {
        // 操作
        QThread::sleep(1);  // 当前线程处理操作用了1s
        // 每执行一次循环发一次信号
        emit sigDone();
        qDebug() << QThread::currentThread() << "sub thread";
        // QMessageBox::aboutQt(NULL);
        if(isStop)
        {
            break;
        }
    }
}

void MyWork::setFlage(bool bl)
{
    isStop = bl;
}

