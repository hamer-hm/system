#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class BaseInfoWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDatabaseChanged(const QString &newPath);

private:
    Ui::MainWindow *ui;
    BaseInfoWidget *m_baseInfo = nullptr;
};

#endif // MAINWINDOW_H
