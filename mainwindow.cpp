#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Multiple Column Sort");

    model = new QStandardItemModel(10, 4,this);
    proxy_model.setSourceModel(model);

    // Attach the model to the view
    ui->tableView->setModel(&proxy_model);

    ui->tableView->setSortingEnabled(true);

    // Generate data
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            QModelIndex index
                = model->index(row,col, QModelIndex());

            model->setData(index,qrand() % 3);
        }
    }

    connect(&column_selection, SIGNAL(orderchanged(QList<QPair<int, int>>))
                              , this, SLOT(orderchanged(QList<QPair<int, int>>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sort_clicked()
{
    column_selection.exec();
}

void MainWindow::orderchanged(QList<QPair<int, int>> order)
{
    proxy_model.setOrder(order);
}
