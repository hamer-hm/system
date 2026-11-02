#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include<QSql>
#include<QSqlDatabase>
class DBManager : public QObject
{
    Q_OBJECT
public:
    static DBManager &instance();
    DBManager(const DBManager&)=delete;
    DBManager& operator=(const DBManager&)=delete;
    void closeDB();
    bool openDB(const QString &path);
    QString getDBPath()const;
    bool setDBPath(const QString &path);
    ~DBManager();
    QSqlDatabase &getDB();
private:
    explicit DBManager(QObject *parent = nullptr);
    QSqlDatabase DB;
    QString dbPath="D:/system/system/steel_sales.db";

};

#endif // DBMANAGER_H
