#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QObject>
#include <QImage>

class MyImage : public QObject
{
    Q_OBJECT
public:
    explicit MyImage(QObject *parent = 0);

    void DrawMyImage();

signals:
    void sigImageDone(QImage img);

public slots:
};

#endif // MYIMAGE_H
