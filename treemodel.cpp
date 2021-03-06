//
// Created by Barry E. Moore II on 8/8/16.
//

#include "treeitem.h"
#include "treemodel.h"
#include <QDebug>

#include <QStringList>

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
  QList<QVariant> rootData;
  rootData << "Molecule" << "Delete";
  rootItem = new TreeItem(rootData);
  setupModelData(data.split(QString("\n")), rootItem);
}

TreeModel::~TreeModel()
{
  delete rootItem;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
  if (parent.isValid())
    return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
  else
    return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{

  //  qDebug()<<"index row  column: "<<index.row()<<index.column();

  if (!index.isValid())
  {
 //     qDebug()<<"!index.isValid()";
    return QVariant();
   }
  if (role != Qt::DisplayRole)
  {
  //     qDebug()<<"ole != Qt::DisplayRole";
    return QVariant();
  }
 // qDebug()<<"[+]";
  TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

  return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
  if (!index.isValid())
    return 0;

  return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return rootItem->data(section);

  return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
const
{
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  TreeItem *parentItem;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  TreeItem *childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
  if (!index.isValid())
    return QModelIndex();

  TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
  TreeItem *parentItem = childItem->parentItem();

  if (parentItem == rootItem)
    return QModelIndex();

  return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
  TreeItem *parentItem;
  if (parent.column() > 0)
    return 0;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  return parentItem->childCount();
}

void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
  QList<TreeItem*> parents;
  QList<int> indentations;
  parents << parent;

  TreeItem *myitem=parents.last();
 // qDebug()<<"myitem->childCount()= "<<myitem->childCount();
 // qDebug()<<"myitem->columnCount()= "<<myitem->columnCount();
 // qDebug()<<"myitem->row(()= "<<myitem->row();

  indentations << 0;

  int number = 0;

  while (number < lines.count()) {

 qDebug()<<"------------------";



    int position = 0;
    while (position < lines[number].length()) {
      if (lines[number].at(position) != ' ')
        break;
      position++;
    }

    QString lineData = lines[number].mid(position).trimmed();
    qDebug()<<"lineData: "<<lineData;

    if (!lineData.isEmpty()) {
      // Read the column data from the rest of the line.
      QStringList columnStrings = lineData.split("|", QString::SkipEmptyParts);
      QList<QVariant> columnData;
      qDebug()<<"!!!"<<columnStrings.count();
      for (int column = 0; column < columnStrings.count(); ++column)
        columnData << columnStrings[column];

      if (position > indentations.last()) {
        // The last child of the current parent is now the new parent
        // unless the current parent has no children.

        if (parents.last()->childCount() > 0) {
          parents << parents.last()->child(parents.last()->childCount()-1);
          indentations << position;

        }
      } else {
        while (position < indentations.last() && parents.count() > 0) {
          parents.pop_back();
          indentations.pop_back();
        }
      }

      // Append a new item to the current parent's list of children.
      qDebug()<<"columnData.count "<<columnData.count();
      qDebug()<<"columnData[0].toString():  "<<columnData[0].toString();

      parents.last()->appendChild(new TreeItem(columnData, parents.last()));






    }

    ++number;
  }
}
