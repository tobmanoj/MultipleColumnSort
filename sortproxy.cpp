#include "sortproxy.h"

#include <QDebug>

SortProxy::SortProxy()
{

}

void SortProxy::setOrder(QList<QPair<int, int> > order)
{
    qDebug()<< order;
    m_sortPriority = order;
    invalidate();
}

bool SortProxy::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    if (m_sortPriority.isEmpty()) return QSortFilterProxyModel::lessThan(source_left, source_right);

    for (auto i = m_sortPriority.constBegin(); i != m_sortPriority.constEnd();++i){
        const QVariant leftData = source_left.model()->index(source_left.row(), i->first, source_left.parent()).data(i->second);
        const QVariant rightData = source_right.model()->index(source_right.row(), i->first, source_right.parent()).data(i->second);
        if (leftData < rightData)
            return true;
        if (rightData < leftData)
            return false;
    }
    return false;
}
