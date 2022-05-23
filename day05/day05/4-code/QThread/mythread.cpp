#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    // 复杂的操作
   // sleep(5);
    for(int i=0; i<100000000; ++i)
    {
        for(int j=0;j<10000000; ++j)
        {

        }
    }
    emit sigDone();
}

