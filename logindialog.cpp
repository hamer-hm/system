#include "logindialog.h"
#include "ui_logindialog.h"
#include<QStandardPaths>
#include<QDir>
#include<QSettings>
#include<QCryptographicHash>
#include<QMessageBox>
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("钢铁销售管理系统");

    //密码框设置为密码隐藏模式
    ui->editPassword->setEchoMode(QLineEdit::Password);
    //读取系统存放配置文件的目录
    QString configDir=QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    if(configDir.isEmpty())
    {
        configDir=QCoreApplication::applicationDirPath();
    }
    //新建存放配置文件目录
    QDir().mkdir(configDir);
    //拼接配置文件路径
    QString iniFile=configDir+"/config.ini";
    m_settings=new QSettings(iniFile,QSettings::IniFormat);
    //从配置文件中读取用户名和密码
    QString userName=m_settings->value("User/userName","admin").toString();
    QString password=m_settings->value("User/password").toString();
    //如果没从配置文件中读到密码，就设置默认密码到配置文件
    if(password.isEmpty())
    {
        m_settings->setValue("User/userName","admin");
        m_settings->setValue("User/password",md5Encrypt("123456"));
        m_settings->sync();
    }
}

LoginDialog::~LoginDialog()
{
    delete ui;
    delete m_settings;
    m_settings=nullptr;
}

//登录按钮
void LoginDialog::on_btnLogin_clicked()
{
    //读取用户输入的用户名和密码
    QString inputUser=ui->editUser->text().trimmed();
    QString inputPswd=ui->editPassword->text().trimmed();
    if(inputUser.isEmpty()||inputPswd.isEmpty())
    {
        QMessageBox::critical(this,"登录失败","用户名或密码为空！");
        return;
    }
    //用MD5加密密码
    QString md5Paswd=md5Encrypt(inputPswd);

    //读取配置文件中的用户名和密码
    QString userName=m_settings->value("User/userName").toString();
    QString password=m_settings->value("User/password").toString();

    //比对密码
    if(password==md5Paswd)
    {
        QMessageBox::information(this,"登录成功","欢迎进入钢材销售系统");
        accept(); // 关闭对话框，返回Accepted
    }else
    {
        QMessageBox::critical(this,"登录失败","用户名或密码错误！");
        ui->editPassword->clear();
        return;
    }

}

//MD5加密函数
QString LoginDialog::md5Encrypt(const QString &password)
{
    //用Md5加密密码
    auto pswd=QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Md5);
    return pswd.toHex();
}
