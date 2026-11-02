#include "systemsettingswidget.h"
#include "ui_systemsettingswidget.h"
#include<QStandardPaths>
#include<QCoreApplication>
#include<QSettings>
#include<QFileDialog>
#include<QMessageBox>
#include"logindialog.h"
#include"dbmanager.h"

SystemSettingsWidget::SystemSettingsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SystemSettingsWidget)
{
    ui->setupUi(this);
    //设置三个密码输入框为密码模式
    ui->editConfirmPswd->setEchoMode(QLineEdit::Password);
    ui->editNewPswd->setEchoMode(QLineEdit::Password);
    ui->editOldPswd->setEchoMode(QLineEdit::Password);
    reload();
}

SystemSettingsWidget::~SystemSettingsWidget()
{
    delete ui;
    delete m_settings;
    m_settings=nullptr;
}
//外部刷新接口（切库时调用）
void SystemSettingsWidget::reload()
{
    loadDBPath();
}

//加载数据库路径
void SystemSettingsWidget::loadDBPath()
{
    QString configDir=QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    if(configDir.isEmpty())
    {
        configDir=QCoreApplication::applicationDirPath();
    }
    QString iniFile=configDir+"/config.ini";
    m_settings=new QSettings(iniFile,QSettings::IniFormat);
    QString dbPath=m_settings->value("dbPath/dbPath").toString();
    ui->editDBPath->setText(dbPath);
}

//浏览数据库路径
void SystemSettingsWidget::on_btnBrowse_clicked()
{
    QString dbPath=QFileDialog::getOpenFileName(this,
                                                  "选择数据库文件",
                                                  QCoreApplication::applicationDirPath(),
                                                  "数据库文件(*.db *.sqlite *.sqlite3)");
    if(!dbPath.isEmpty())
    {
        if (!DBManager::instance().setDBPath(dbPath)) {
            QMessageBox::critical(this, "错误", "无法打开该数据库");
            return;
        }
        ui->editDBPath->setText(dbPath);
        QMessageBox::information(this, "成功", "数据库已切换");
        emit dbPathChanged();

    }
}

//保存密码
void SystemSettingsWidget::on_btnSave_clicked()
{
    //配置文件中的旧密码
    QString oldPswd=m_settings->value("User/password").toString();
    //用户输入的旧密码
    QString inputOldPswd=ui->editOldPswd->text().trimmed();
    if(inputOldPswd.isEmpty())
    {
        QMessageBox::warning(this,"失败","请输入旧密码！");
        return;
    }
    QString inputOldPswdEnc=LoginDialog::md5Encrypt(inputOldPswd);
    if(oldPswd!=inputOldPswdEnc)
    {
        QMessageBox::warning(this,"失败","旧密码输入错误！");
        return;
    }

    //新密码
    QString inputNewPswd=ui->editNewPswd->text().trimmed();
    //确认密码
    QString inputConfirmPswd=ui->editConfirmPswd->text().trimmed();
    if(inputNewPswd.isEmpty())
    {
        QMessageBox::warning(this,"失败","请输入新密码！");
        return;
    }
    if(inputConfirmPswd.isEmpty())
    {
        QMessageBox::warning(this,"失败","请确认密码！");
        return;
    }
    if(inputNewPswd!=inputConfirmPswd)
    {
        QMessageBox::warning(this,"失败","两次密码输入不同！");
        return;
    }
    if(inputOldPswd==inputNewPswd)
    {
        QMessageBox::warning(this,"失败","新密码与旧密码相同！");
        return;
    }
    QString newPswd=LoginDialog::md5Encrypt(inputNewPswd);
    m_settings->setValue("User/password",newPswd);
    QMessageBox::warning(this,"成功","修改密码成功！");
    //清空输入框
    ui->editConfirmPswd->clear();
    ui->editNewPswd->clear();
    ui->editOldPswd->clear();
}

