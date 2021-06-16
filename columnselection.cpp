#include "columnselection.h"
#include "ui_columnselection.h"

ColumnSelection::ColumnSelection(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ColumnSelection)
{
    ui->setupUi(this);
}

ColumnSelection::~ColumnSelection()
{
    delete ui;
}

void ColumnSelection::on_sort_clicked()
{
    order.clear();
    if (ui->one->text().toInt() != -1) {
        order.append({ui->one->text().toInt(), Qt::DisplayRole});
    }

    if (ui->two->text().toInt() != -1) {
        order.append({ui->two->text().toInt(), Qt::DisplayRole});
    }

    if (ui->three->text().toInt() != -1) {
        order.append({ui->three->text().toInt(), Qt::DisplayRole});
    }

    emit orderchanged(order);
}

