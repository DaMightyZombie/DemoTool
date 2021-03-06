#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>

#include "demolistmodel.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_FilterDemos_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    DemoListModel * demoListModel;
    QSortFilterProxyModel * proxyModel;
};
#endif // MAINWINDOW_H
