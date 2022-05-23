#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->login, &QPushButton::clicked, [=]()
    {
        QString name = ui->userName->text();
        QString pwd = ui->passwd->text();
        if(name.isEmpty())
        {
            QMessageBox::warning(this, "username", "用户名不能为空");
            return;
        }
        if(pwd.isEmpty())
        {
            QMessageBox::warning(this, "passwd", "密码不能为空");
            return;
        }
        if(name != "itcast" || pwd != "itcast")
        {
            QMessageBox::warning(this, "warning", "用户名或密码错误");
            return;
        }
        QDialog::accept();
    });
}

Login::~Login()
{
    delete ui;
}

void Login::on_exit_clicked()
{
    QDialog::reject();  // 拒绝
}
