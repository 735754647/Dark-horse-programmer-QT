#ifndef CARMANAGER_H
#define CARMANAGER_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDomDocument>
#include <QItemDelegate>
#include <QComboBox>
#include <QSqlTableModel>

// 自定义代理类
class MyDelegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        // 设置第4列的代理 color
        if(index.column() == 3)
        {
            QComboBox* combox = new QComboBox(parent);
            // 初始化
            combox->addItem("黑色");
            combox->addItem("红色");

            int color = index.data(Qt::EditRole).toInt();
            combox->setCurrentIndex(color);
            return combox;
        }
        return QItemDelegate::createEditor(parent, option, index);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
    {
        if(index.column() == 3)
        {
            QComboBox* combox = static_cast<QComboBox*>(editor);
            if(combox->currentText() == "黑色")
            {
                model->setData(index, 0);
            }
            else
            {
                model->setData(index, 1);
            }
            return;
        }
        QItemDelegate::setModelData(editor, model, index);
    }
};

class MySqlTableModel : public QSqlTableModel
{
public:
    QVariant data(const QModelIndex &idx, int role) const
    {
        // color列
        if(idx.column() == 3 && role == Qt::DisplayRole)
        {
            QVariant data = QSqlTableModel::data(idx, role);
            if(data.toInt() == 0)
            {
                return "黑色";
            }
            else
            {
                return "红色";
            }
        }
        return QSqlTableModel::data(idx, role);
    }
};


namespace Ui {
class CarManager;
}

class CarManager : public QMainWindow
{
    Q_OBJECT

public:
    enum DateTimeType{Date, Time, DateTime};
    explicit CarManager(QWidget *parent = 0);
    ~CarManager();

    bool connectDB();
    // 出售车辆界面初始化
    void initSaleCar();
    // 创建xml文件(空的)
    void createXML();
    // 写数据到xml文件(内存中的操作, 写到了doc对象中)
    void writeXMLData();
    // 销售记录（读xml文件数据）
    void showDailyList();
    // 初始化统计界面
    void initTongji();
    // 初始化新车入库
    void initNewCar();

    // 从磁盘中读数据
    bool readXML();
    // 将数据写到磁盘中
    bool writeXML();
    // 获取时间
    QString getDateTime(DateTimeType type);
    void createNodes(QDomElement & parent);

public slots:
    void factoryChanged(const QString & name);
    void brandChanged(const QString &name);

private:
    Ui::CarManager *ui;
    QSqlDatabase m_db;
    QDomDocument m_doc;
};

#endif // CARMANAGER_H
