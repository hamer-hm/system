#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QButtonGroup>
#include"dbmanager.h"
#include<QSettings>
#include<QStandardPaths>
#include<QMessageBox>
#include<QDir>
#include<QCoreApplication>
#include"baseinfowidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 配置文件路径
    QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    if (configDir.isEmpty()) {
        configDir = QCoreApplication::applicationDirPath();   // 极端情况下兜底
    }
    QDir().mkpath(configDir);                                  // 目录可能不存在，先建

    QString iniFile = configDir + "/config.ini";
    QSettings setting(iniFile, QSettings::IniFormat);

    QString defaultDbPath = QCoreApplication::applicationDirPath() + "/steel_sales.db";
    QString dbPath = setting.value("dbPath", defaultDbPath).toString();

    if (!setting.contains("dbPath"))
    {
        setting.beginGroup("dbPath");
        setting.setValue("dbPath", dbPath);
        setting.endGroup();
        setting.sync();   // 强制写盘
    }
    // 打开数据库
    bool res = DBManager::instance().openDB(dbPath);

    ui->setupUi(this);

    // 获取提升后的 BaseInfoWidget
    m_baseInfo = ui->page_BaseInfo;

    // 连信号：切库后刷新
    connect(&DBManager::instance(), &DBManager::databaseChanged,
            this, &MainWindow::onDatabaseChanged);

    // toolbutton按钮组
    QButtonGroup *btnGroup = new QButtonGroup(this);

    btnGroup->addButton(ui->btn_BaseInfo, 0);
    btnGroup->addButton(ui->btn_Stockton, 1);
    btnGroup->addButton(ui->btn_SaleCreate, 2);
    btnGroup->addButton(ui->btn_OrderQuery, 3);
    btnGroup->addButton(ui->btn_Customer, 4);
    btnGroup->addButton(ui->btn_Report, 5);
    btnGroup->addButton(ui->btn_Setting, 6);
    // 切换stackedWidget页面
    connect(btnGroup, &QButtonGroup::idClicked, ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // 判断数据库打开成不成功
    if(!res)
    {
        QMessageBox::critical(this, "数据库错误",
                              "无法打开数据库：\n" + dbPath + "\n\n请检查 config.ini 中的 dbPath");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDatabaseChanged(const QString &newPath)
{
    qDebug() << "[MainWindow] 数据库已切换到：" << newPath;

    if (m_baseInfo)
        m_baseInfo->reloadTable();

    // 其他页面刷新
    // ui->page_Stock->loadStockTable();
    // ui->page_Sale->loadInformation();
}
