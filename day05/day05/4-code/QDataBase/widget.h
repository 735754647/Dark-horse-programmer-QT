#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>   // 数据模型
// 显示模型中的数据, 需要使用视图 QTableView - QSqlTableModel
// qt model - view 模型

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_submit_clicked();

    void on_revert_clicked();

    void on_search_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel* model;
};

#endif // WIDGET_H
