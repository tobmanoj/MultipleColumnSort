#ifndef SORTPROXY_H
#define SORTPROXY_H

#include <QSortFilterProxyModel>
#include <qset.h>

class SortProxy : public QSortFilterProxyModel
{
public:
    SortProxy();

    void setOrder(QList<QPair<int, int>> order);


protected:
    bool lessThan(const QModelIndex & source_left, const QModelIndex & source_right) const;

    QList<QPair<int, int>> m_sortPriority;

};

#endif // SORTPROXY_H
