#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setFixedSize(195, 210);

    connect(ui->login, &QPushButton::clicked, [=]()
    {
        QString name = ui->userID->text();
        QString pwd = ui->pwd->text();

        if(name.isEmpty() == true)
        {
            QMessageBox::warning(this, "ueername", "用户名不能为空!");
            return;
        }
        if(pwd.isEmpty() == true)
        {
            QMessageBox::warning(this, "pwd", "密码不能为空!");
            return;
        }

        if((name != "itcast") || (pwd != "itcast"))
        {
            QMessageBox::critical(this, "error", "用户名或密码输入错误!");
            return;
        }
        // 接受
        // 模态对话框结束
        this->accept();
        // QDialog::accept(); // QDialog::Accepted
    });
}

Login::~Login()
{
    delete ui;
}

void Login::on_exit_clicked()
{
    // 拒绝
    // QDialog::Rejected
    QDialog::reject();
}
