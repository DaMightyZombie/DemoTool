#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hldemo.hpp"
#include "demolistmodel.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    demoListModel = new DemoListModel(this);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(demoListModel);
    ui->demoListTable->setModel(proxyModel);
    ui->demoListTable->verticalHeader()->hide();
    ui->demoListTable->setSortingEnabled(true);
    ui->demoListTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->demoListTable->resizeColumnsToContents();
    ui->demoListTable->show();
}

MainWindow::~MainWindow()
{
    delete demoListModel;
    delete proxyModel;
    delete ui;
}

