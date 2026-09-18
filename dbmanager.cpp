#include "dbmanager.h"
#include<QMessageBox>
#include<QCoreApplication>
#include<QDir>
#include<QSettings>
#include<QSqlQuery>
DBManager &DBManager::instance()
{
    static DBManager instance;
    return instance;
}
//关闭数据库
void DBManager::closeDB()
{
    if(DB.open())
    {
        DB.close();
    }
}
//打开数据库
bool DBManager::openDB(const QString &path)
{
    if(path.isEmpty())
        return false;
    DB.setDatabaseName(path);
    if(!DB.open())
    {

        return false;
    }else
    {
        dbPath=path;
        QSqlQuery query(DB);
        query.exec("PRAGMA foreign_keys = ON;");
        return true;
    }
}
//获取数据库路径
QString DBManager::getDBPath() const
{
    return dbPath;
}

//设置数据库路径
void DBManager::setDBPath(const QString &path)
{
    if(dbPath==path)
        return;
    dbPath=path;
    closeDB();
    openDB(path);

    QString iniFile = QCoreApplication::applicationDirPath() + "/config.ini";//设置ini文件路径
    QSettings setting(iniFile,QSettings::IniFormat);//新建ini文件
    setting.setValue("dbPath",dbPath);
}

DBManager::DBManager(QObject *parent)
    : QObject{parent}
{
    DB=QSqlDatabase::addDatabase("QSQLITE");

}

DBManager::~DBManager()
{
    closeDB();
}

QSqlDatabase& DBManager::getDB()
{
    qDebug() << "db file path:" << DB.databaseName();
    return DB;
}

