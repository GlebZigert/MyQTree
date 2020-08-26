//
// Created by Barry E. Moore II on 8/8/16.
//

#ifndef SIMPLETREEMODEL_TREEMODEL_H
#define SIMPLETREEMODEL_TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class TreeItem;

class TreeModel : public QAbstractItemModel
{
  Q_OBJECT

public:
  explicit TreeModel(const QString &data, QObject *parent = 0);
  ~TreeModel();

  QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
  Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QModelIndex index(int row, int column,
                    const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
  int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    void appendItem(QModelIndex &parent, TreeItem *item);

private:
  void setupModelData(const QStringList &lines, TreeItem *parent);

  TreeItem *rootItem;
};


#endif //SIMPLETREEMODEL_TREEMODEL_H
