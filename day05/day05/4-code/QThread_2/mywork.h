#ifndef MYWORK_H
#define MYWORK_H

#include <QObject>

class MyWork : public QObject
{
    Q_OBJECT
public:
    explicit MyWork(QObject *parent = 0);

    // 业务处理函数
    void doMyWork();

    void setFlage(bool bl);

signals:
    void sigDone();

public slots:
private:
    bool isStop;
};

#endif // MYWORK_H
