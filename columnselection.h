#ifndef COLUMNSELECTION_H
#define COLUMNSELECTION_H

#include <QList>
#include <QDialog>

namespace Ui {
class ColumnSelection;
}

class ColumnSelection : public QDialog
{
    Q_OBJECT

public:
    explicit ColumnSelection(QDialog *parent = nullptr);
    ~ColumnSelection();

signals:
    void orderchanged(QList<QPair<int, int>>);

private slots:
    void on_sort_clicked();

private:
    Ui::ColumnSelection *ui;

    QList<QPair<int, int>> order;
};

#endif // COLUMNSELECTION_H
