#include "mymodel.h"
#include <QDebug>
//#include <QStringList>

MyModel::MyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    this->rootItem=new MyItem(nullptr);

    MyItem *item = new MyItem(nullptr);
    item->name="System";
    item->type="System";
    rootItem->m_child_list.append(item);

    item->m_parent=rootItem;

    MyItem *item1=new MyItem(nullptr);
     item1->name="1";
     item1->type="1";
     item->m_child_list.append(item1);

     item1->m_parent=item;

     MyItem *item11=new MyItem(nullptr);
      item11->name="11";
      item11->type="11";
      item1->m_child_list.append(item11);

      item11->m_parent=item1;

      MyItem *item12=new MyItem(nullptr);
       item12->name="12";
       item12->type="12";
       item1->m_child_list.append(item12);

       item12->m_parent=item1;


     MyItem *item2=new MyItem(nullptr);
      item2->name="2";
      item2->type="2";
      item->m_child_list.append(item2);

      item2->m_parent=item;

      MyItem *item3=new MyItem(nullptr);
       item3->name="3";
       item3->type="3";
       item->m_child_list.append(item3);

       item3->m_parent=item;

    /*
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
        */
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

     MyItem *item = static_cast<MyItem*>(index.internalPointer());


    if(role == Qt::DecorationRole/* &&
       rootItem != item*/)
    {
     //    qDebug()<<"[pxm]";
        QPixmap pxm;
        switch(index.column())
        {
            case 0:
            {
       //     qDebug()<<"[pxm]";
                pxm = item->getViewPxm();
                break;
            }
            case 2:
            {
            //    pxm = item->getViewRssiPxm();
                break;
            }
            default:
            {
                break;
            }
        }
        if(pxm.isNull())
            return QVariant();
         return QVariant(pxm);
    }





if (role == Qt::DisplayRole)
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

 return QVariant();

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
    if (index.isValid())
    {

    this->beginInsertRows(index.parent(),index.row(),index.row());
//    this->beginResetModel();
                        qDebug()<<"MyModel::append_item";

    MyItem *parent = static_cast<MyItem*>(index.internalPointer());

  //  qDebug()<<"++++++++++++parent name "<<parent->name;

    parent->m_child_list.append(item);

    item->m_parent=parent;


    this->endInsertRows();
    emit dataChanged(index,index);

//this->endResetModel();
    return true;
    }
    qDebug()<<"not valid!!!";
    return false;
}

bool MyModel::delete_item(const QModelIndex &index)
{
    if(this->parent(index).isValid())
    {
    this->beginRemoveRows(index.parent(),index.row(),index.row());
    MyItem *parent = static_cast<MyItem*>(this->parent(index).internalPointer());

    parent->m_child_list.removeAt(index.row());



   /* MyItem *item = static_cast<MyItem*>(index.internalPointer());

    int res=1;

    while(1==res)
    {

     if(this->rowCount(index)>0)
         index=this->index(0,0,index);


    }*/


    //emit dataChanged(index,index);
    this->endRemoveRows();
    emit dataChanged(index,index);
    }
    else
    qDebug()<<"no valid";
}

void MyModel::test()
{
    int res=1;
    QModelIndex parent=this->index(0,0);

    qDebug()<<this->data(parent,Qt::DisplayRole);


    QModelIndex ind=this->index(0,0,parent);

int row=0;

    qDebug()<<this->data(this->index(row,0,ind.parent()),Qt::DisplayRole).toString();
    qDebug()<<this->data(this->index(row,1,ind.parent()),Qt::DisplayRole).toString();

    int rows=this->rowCount(ind.parent());
    qDebug()<<"rows: "<<rows;

   // rootItem->show_children();

/*
    while(1==res)
        {
     qDebug()<<"--------------------------------------";
     qDebug()<<this->data(this->index(row,0,ind.parent()),Qt::DisplayRole).toString();
     qDebug()<<this->data(this->index(row,1,ind.parent()),Qt::DisplayRole).toString();

     if(this->rowCount(ind))
     {
     ind=this->index(0,0,ind);
             row=0;

     }
     else
     if(row<this->rowCount(ind.parent())-1)
     {
     row++;
     }
     else
     if(ind.parent().isValid())
     {
         parent=ind.parent();
         if(ind.row()<this->rowCount(parent)-1)
         {

         ind=this->index(ind.parent().row()+1,0,ind.parent().parent());
         row=ind.row();
         }
         else
             res=0;
     }
     else
     {
     res=0;
     }


        }/*


 /*    while(1==res)
    {
 qDebug()<<"--------------------------------------";
 qDebug()<<this->data(this->index(row,0,ind.parent()),Qt::DisplayRole);
 qDebug()<<this->data(this->index(row,1,ind.parent()),Qt::DisplayRole);

 row=ind.row()+1;

    if(row<this->rowCount(ind.parent()))
    {
        ind=(row,0,ind.parent());

    }
    else
    {
        res=0;
    }
       QModelIndex child,parent;
        parent=index.parent();
        child=this->index(0,0,index);
        if(child.isValid())
        {
            qDebug()<<"have a child";
            index=this->index(index.row(),0,parent);

        }
        else
        {
         qDebug()<<"NO child";
         res=0;

        }

    }*/
}

int MyModel::load_settings(QString ini_file)
{
    rootItem->m_child_list.clear();
    MyItem *item = new MyItem(nullptr);
    item->name="Система";
    item->type="Система";
    rootItem->m_child_list.append(item);

    item->m_parent=rootItem;


   // QSettings settings("/home/gleb/MyTree/rifx.ini",QSettings::IniFormat);
    QSettings settings(ini_file,QSettings::IniFormat);
    settings.beginGroup("TREE");
    int count=settings.value("Count",-1).toInt();
    qDebug()<<"device count: "<<count;
    settings.endGroup();

    if(0>=count)
        return 0;



    settings.setIniCodec( "Windows-1251" );


    QModelIndex ind=this->index(0,0);
    qDebug()<<"DATA..."<<this->data(ind,Qt::DisplayRole).toString();


    /*
    QStringList ls_childgroup=settings.childGroups();
    for(int i=0;i<ls_childgroup.count();i++)
        qDebug()<<ls_childgroup.at(i);
    */



    QList<MyItem> ls_item;
    for(int index=0;index<count;index++)
    {
        QString strGroup("Obj_%1");
    //    qDebug()<<strGroup;
        strGroup=strGroup.arg(index+1);
    //    qDebug()<<strGroup;
    //    qDebug()<<"==================";
        if(settings.childGroups().contains(strGroup))
        {
            settings.beginGroup(strGroup);

            MyItem *tmpItem = new MyItem(nullptr);
            tmpItem->name=settings.value("Name", -1).toString();
            tmpItem->type=settings.value("Type", -1).toString();

            if(!tmpItem->name.isEmpty())
            {

                this->append_item(ind,tmpItem); //надо не добавлять по одиночке к руту

                                                //надо собрать дерево и записать указатель на дерево в переменную рута.
            }



            settings.endGroup();

        }

    }



}

int MyModel::save_settings(QString path)
{
  QModelIndex ind=this->index(0,0);
  qDebug()<<this->data(ind,Qt::DisplayRole).toString();

   QSettings settings(path,QSettings::IniFormat);

   settings.clear();
   settings.beginGroup("TREE");
 //  qDebug()<<"TREE";
//   qDebug()<<"Count"<<this->rowCount(ind);
   settings.setValue("Count",this->rowCount(ind));
   settings.endGroup();

   MyItem *item = static_cast<MyItem*>(ind.internalPointer());


   if(item->childCount()>0)
   item->show_children(&settings,"",0);
   /*
   qDebug()<<this->rowCount(ind);
   settings.setValue("Count",this->rowCount(ind));
   settings.endGroup();




   for(int i=0;i<this->rowCount(ind);i++)
   {
        QString strGroup("Obj_%1");
        strGroup=strGroup.arg(i+1);

        settings.beginGroup(strGroup);


        settings.setValue("Name",this->data(this->index(i,0,ind),Qt::DisplayRole).toString());
        settings.setValue("Type",this->data(this->index(i,1,ind),Qt::DisplayRole).toString());

        settings.endGroup();


   }

   */
}


















