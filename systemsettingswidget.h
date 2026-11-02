#ifndef SYSTEMSETTINGSWIDGET_H
#define SYSTEMSETTINGSWIDGET_H

#include <QWidget>
class QSettings;
namespace Ui {
class SystemSettingsWidget;
}

class SystemSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSettingsWidget(QWidget *parent = nullptr);
    ~SystemSettingsWidget();
    //外部刷新接口（切库时调用）
    void reload();
private slots:
    void on_btnBrowse_clicked();

    void on_btnSave_clicked();

private:
    Ui::SystemSettingsWidget *ui;
    //加载数据库路径
    void loadDBPath();
    QSettings *m_settings=nullptr;
signals:
    void dbPathChanged();
};

#endif // SYSTEMSETTINGSWIDGET_H
