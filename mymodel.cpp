#include "mymodel.h"
#include <QDebug>

MyModel::MyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    this->rootItem=new MyItem(nullptr);
        rootItem->name="Root";
        rootItem->type="device";

       MyItem *item=new MyItem(nullptr);
        item->name="first";
        item->type="block";
                rootItem->m_child_list.append(item);

        item->m_parent=rootItem;

       MyItem *item2=new MyItem(nullptr);
        item2->name="2second";
        item2->type="2block";
                item->m_child_list.append(item2);

        item2->m_parent=item;

        MyItem *item3=new MyItem(nullptr);
        item3->name="3third";
        item3->type="3block";
                item->m_child_list.append(item3);

        item3->m_parent=item;


        MyItem *item4=new MyItem(nullptr);
        item4->name="fourch";
        item4->type="4 block";

        this->append_item(this->index(0,0),item4);


        MyItem *item5=new MyItem(nullptr);
        item5->name="555";
        item5->type="5 block";

        this->append_item(this->index(0,0),item5);
}

MyModel::~MyModel()
{
delete rootItem;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
//    qDebug()<<"MyModel::data";
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

    MyItem *item = static_cast<MyItem*>(index.internalPointer());

    switch(index.column())
    {
        case 0:
  //      qDebug()<<item->name;
        return item->name;
        break;

        case 1:
  //       qDebug()<<item->type;
        return item->type;
        break;

    }
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
      return 0;

    return QAbstractItemModel::flags(index);
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    switch(section)
    {
        case 0:
  //      qDebug()<<item->name;
        return rootItem->name;
        break;

        case 1:
  //       qDebug()<<item->type;
        return rootItem->type;
        break;

    }
 return QVariant();

}

QModelIndex MyModel::index(int row, int column, const QModelIndex &parent) const
{
  //      qDebug()<<"MyModel::index";
    if (!hasIndex(row, column, parent))
      return QModelIndex();

    MyItem *parentItem;

    if (!parent.isValid())
    {
//        qDebug()<<"!parent.isValid()";
    parentItem = rootItem;
    }

    else
    {
  //           qDebug()<<"parent.isValid()";
     parentItem = static_cast<MyItem*>(parent.internalPointer());
    }


    MyItem *childItem = parentItem->m_child_list.value(row);
    if (childItem)
    {
//    qDebug()<<"childItem";
    return createIndex(row, column, childItem);
    }

    else
      {
 //        qDebug()<<"!childItem";
        return QModelIndex();

      }

}

QModelIndex MyModel::parent(const QModelIndex &index) const
{
 //           qDebug()<<"MyModel::parent";
    if (!index.isValid())
      return QModelIndex();

    MyItem *childItem = static_cast<MyItem*>(index.internalPointer());
    MyItem *parentItem = childItem->m_parent;

    if (parentItem == rootItem)
      return QModelIndex();


    return createIndex(parentItem->row(), 0, parentItem);
}

int MyModel::rowCount(const QModelIndex &parent) const
{
//                qDebug()<<"MyModel::rowCount";
    MyItem *parentItem;
    if (parent.column() > 0)
      return 0;

    if (!parent.isValid())
      parentItem = rootItem;
    else
      parentItem = static_cast<MyItem*>(parent.internalPointer());

    return parentItem->childCount();

}

int MyModel::columnCount(const QModelIndex &parent) const
{
   //                 qDebug()<<"MyModel::columnCount";
    return 2;
}

bool MyModel::append_item(const QModelIndex &index, MyItem *item)
{
//    this->beginResetModel();
                        qDebug()<<"MyModel::append_item";

    MyItem *parent = static_cast<MyItem*>(index.internalPointer());

  //  qDebug()<<"++++++++++++parent name "<<parent->name;

    parent->m_child_list.append(item);

    item->m_parent=parent;

    emit dataChanged(index,index);
//this->endResetModel();
    return true;
}
