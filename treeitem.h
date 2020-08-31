//
// Created by Barry E. Moore II on 8/8/16.
//

#ifndef SIMPLETREEMODEL_TREEITEM_H
#define SIMPLETREEMODEL_TREEITEM_H

#include <QList>
#include <QVariant>

class TreeItem
{
public:
  explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = 0);
  ~TreeItem();

  void appendChild(TreeItem *child);

  TreeItem *child(int row);
  int childCount() const;
  int columnCount() const;
  QVariant data(int column) const;
  int row() const;
  TreeItem *parentItem();

private:
  QList<TreeItem*> m_childItems;
  QList<QVariant> m_itemData;
  TreeItem *m_parentItem;
};


#endif //SIMPLETREEMODEL_TREEITEM_H
