#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 添加一个mysql数据库
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //  设置数据库
    db.setHostName("127.0.0.1");    // 主机IP
    db.setUserName("root"); // 登录mysql数据库的用户名
    db.setPassword("root"); // 登录密码
    db.setDatabaseName("itcast"); // 连接的数据库名
    // 打开数据库
    if(db.open() == false)
    {
        QMessageBox::warning(this, "warning", db.lastError().text());
    }

    // 增删查改 ...
    // 添加一条记录
    QSqlQuery query;
//    QString sql = "insert into people(name, age) values('张三丰', 123)";
//    query.exec(sql);
    // 预处理
    // ? -- 通配符, odbc风格的通配符
//    query.prepare("insert into people(name, age) values(?, ?)");
//    // 添加绑定数据
//    QVariantList nameList;
//    nameList << "aa" << "bb" << "cc";
//    query.addBindValue(nameList);
//    QVariantList ageList;
//    ageList << 12 << 13 << 14;
//    query.addBindValue(ageList);
//    // 执行批处理
//    query.execBatch();

    // oracle 风格的通配符
    // 定义方式:          :+自定义的名字
//    query.prepare("insert into people(name, age) values(:name, :age)");
//    // 添加绑定数据
//    QVariantList ageList;
//    ageList << 12 << 13 << 14;
//    query.bindValue(":age", ageList);
//    QVariantList nameList;
//    nameList << "aa11" << "bb222" << "cc333";
//    query.bindValue(":name", nameList);
//    // 执行批处理
//    query.execBatch();

    // 数据查询
    query.exec("select name, age from people");
    while(query.next()) // 遍历每一条记录
    {
        qDebug() << query.value(0).toString().toUtf8().data() // 0 -- 第一个字段的索引
                 << query.value("name").toString().toUtf8().data();
    }

    // 1. 实例化model
    model = new QSqlTableModel(this);
    // 2. 将模型设置到视图中
    ui->tableView->setModel(model);
    // 3. 给model设置数据库表 -- 前提条件: 数据库已经打开了
    model->setTable("student");
    // 4. 查询表
    model->select();
    // 5. 设置表头
    model->setHeaderData(0, Qt::Horizontal, "编号");

    // 6. 设置提交模式
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_submit_clicked()
{
    model->submitAll();
}

void Widget::on_revert_clicked()
{
    model->revertAll(); // 撤销步骤
    model->submitAll(); // 提交步骤 -- 更新数据模型 model->select();
}

void Widget::on_search_clicked()
{
    QString name = ui->lineEdit->text();    // 查询的人的名字

    //slect * from aa  where name = 'xiaoming';
    // 设置过滤条件
    QString sql = QString("name='%1'").arg(name);
    model->setFilter(sql);
    // 重新查询
    model->select();
}
