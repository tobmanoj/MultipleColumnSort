#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "columnselection.h"
#include "sortproxy.h"

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
    void on_sort_clicked();
    void orderchanged(QList<QPair<int, int> >);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;

    SortProxy proxy_model;

    ColumnSelection column_selection;
};
#endif // MAINWINDOW_H
