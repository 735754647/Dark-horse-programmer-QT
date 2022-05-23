#include "mainwindow.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 登录对话框对象
    Login login;
    if(QDialog::Accepted == login.exec())
    {
        // 主窗口对象
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        return 0;
    }



}
