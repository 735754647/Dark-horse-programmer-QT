#include "mainwindow.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    if(login.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
