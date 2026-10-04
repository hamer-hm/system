#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
class QSettings;
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    //MD5加密函数
    static QString md5Encrypt(const QString &password);
private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;

    QSettings *m_settings=nullptr;
};

#endif // LOGINDIALOG_H
