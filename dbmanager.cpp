#include "dbmanager.h"
#include<QMessageBox>
#include<QCoreApplication>
#include<QDir>
#include<QSettings>
#include<QSqlQuery>
#include<QStandardPaths>
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
bool DBManager::setDBPath(const QString &path)
{
    if (path.isEmpty())
        return false;

    if (dbPath == path)
        return true;

    const QString oldPath = dbPath;

    // 1. 关闭旧库，尝试打开新库
    closeDB();
    if (!openDB(path)) {
        // 2. 失败回滚到旧库
        if (!oldPath.isEmpty())
            openDB(oldPath);
        return false;
    }

    // 3. 成功才写 ini
    QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    if (configDir.isEmpty())
        configDir = QCoreApplication::applicationDirPath();
    //路径不存在创建路径
    QDir().mkpath(configDir);

    QSettings setting(configDir + "/config.ini", QSettings::IniFormat);
    setting.beginGroup("dbPath");
    setting.setValue("dbPath", path);
    setting.endGroup();
    setting.sync();   // 立即写盘
    return true;
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
    return DB;
}

