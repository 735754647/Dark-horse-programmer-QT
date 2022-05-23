#include "mytest.h"
#include "ui_mytest.h"

MyTest::MyTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTest)
{
    ui->setupUi(this);
}

MyTest::~MyTest()
{
    delete ui;
}
