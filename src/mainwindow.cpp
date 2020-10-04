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
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(-1); // Filter all columns
    ui->demoListTable->setModel(proxyModel);
    ui->demoListTable->setAlternatingRowColors(true);
    ui->demoListTable->setShowGrid(false);
    ui->demoListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->demoListTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->demoListTable->verticalHeader()->hide();
    ui->demoListTable->setSortingEnabled(true);
    ui->demoListTable->resizeColumnsToContents();
    ui->demoListTable->show();
}

MainWindow::~MainWindow()
{
    delete demoListModel;
    delete proxyModel;
    delete ui;
}


void MainWindow::on_lineEdit_FilterDemos_textChanged(const QString &arg1)
{
    proxyModel->setFilterFixedString(arg1);
}
