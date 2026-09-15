#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QButtonGroup>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //toolbutton按钮组
    QButtonGroup *btnGroup=new QButtonGroup(this);

    btnGroup->addButton(ui->btn_BaseInfo,0);
    btnGroup->addButton(ui->btn_Stockton,1);
    btnGroup->addButton(ui->btn_SaleCreate,2);
    btnGroup->addButton(ui->btn_OrderQuery,3);
    btnGroup->addButton(ui->btn_Customer,4);
    btnGroup->addButton(ui->btn_Report,5);
    btnGroup->addButton(ui->btn_Setting,6);
    //切换stackedWidget页面
    connect(btnGroup,&QButtonGroup::idClicked,ui->stackedWidget,&QStackedWidget::setCurrentIndex);

}

MainWindow::~MainWindow()
{
    delete ui;
}


