#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

protected:
    void run(); // 入口函数 -- 需要start()启动

signals:
    void sigDone();

public slots:
};

#endif // MYTHREAD_H
