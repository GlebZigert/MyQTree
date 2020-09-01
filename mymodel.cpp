#include "mymodel.h"
#include <QDebug>
#include <QStack>
//#include <QStringList>

MyModel::MyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    ID::set_zero();
    this->rootItem=new MyItem(nullptr);
   // rootItem->ID=1;
    rootItem->Name="Дерево устройств";
    rootItem->type="ROOT_TYPE";

    MyItem *item = new MyItem(nullptr);
   // qDebug()<<"id "<<item->ID;
    item->Name="System";
    item->type="System";
    rootItem->m_child_list.append(item);

    item->m_parent=rootItem;
/*
    MyItem *item1=new MyItem(nullptr);
 //   qDebug()<<"id "<<item1->ID;
     item1->name="1";
     item1->type="1";
     item->m_child_list.append(item1);

     item1->m_parent=item;

     MyItem *item11=new MyItem(nullptr);
    // qDebug()<<"id "<<item11->ID;
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
*/
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
        return item->Name;
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
        return rootItem->Name;
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
    qDebug()<<"append item: index not valid!!!";
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
    item->Name="System";
    item->type="System";
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
            tmpItem->Name=settings.value("Name", -1).toString();
            tmpItem->type=settings.value("Type", -1).toString();

            if(!tmpItem->Name.isEmpty())
            {

                this->append_item(ind,tmpItem); //надо не добавлять по одиночке к руту

                                                //надо собрать дерево и записать указатель на дерево в переменную рута.
            }



            settings.endGroup();

        }

    }



}

int MyModel::load_settings_1(QString ini_file)
{
    qDebug()<<"=============================== ";
     qDebug()<<"= ";
     qDebug()<<"= ";
     qDebug()<<"=      load_settingd_1";
     qDebug()<<"= ";
     qDebug()<<"= ";
     qDebug()<<"============================== ";
    rootItem->m_child_list.clear();
    MyItem *item = new MyItem(nullptr);
    item->Name="System";
    item->type="System";
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

    QStack<int> st_current;
    int current=0;
    QStack<int> st_vsego;
    int vsego=count;
    int child_cnt=0;
    int cnt=0;
    int deep=0;

    for(int index=0;index<count;index++)
    {
        qDebug()<<("----------------");
        QString strGroup("Obj_%1");

        strGroup=strGroup.arg(index+1);
        qDebug()<<strGroup;
    //    qDebug()<<strGroup;
    //    qDebug()<<"==================";
        if(settings.childGroups().contains(strGroup))
        {
            settings.beginGroup(strGroup);




            QString name=settings.value("Name", -1).toString();
            QString type=settings.value("Type", -1).toString();



            MyItem *tmpItem = new MyItem(nullptr,name,type);

            child_cnt=0;
            child_cnt=settings.value("Count", -1).toInt();

            qDebug()<<"name   "<< tmpItem->Name  ;
            qDebug()<<"type   "<< tmpItem->type  ;

            if(type=="СД")
            {
                tmpItem->Num2=settings.value("Num2", -1).toInt();
                tmpItem->DK=settings.value("DK", -1).toInt();
                tmpItem->Bazalt=settings.value("Bazalt", -1).toInt();
                tmpItem->ConnectBlock=settings.value("ConnectBlock", -1).toInt();
                tmpItem->UdpUse=settings.value("UdpUse", -1).toInt();
                if(tmpItem->UdpUse>0)
                {
                    tmpItem->UdpAdress=settings.value("UdpAdress", -1).toString();
                    tmpItem->UdpPort=settings.value("UdpPort", -1).toInt();
                }

            }
         //   qDebug()<<"cnt   "<< cnt  ;


            if(!tmpItem->Name.isEmpty())
            {

                this->append_item(ind,tmpItem); //надо не добавлять по одиночке к руту
                current++;
            }

            if(deep>0)
            {
                qDebug()<<"deep "<<deep;

                qDebug()<<"is "<<current<<" from "<<vsego;

            }

            if(child_cnt>0)
            {
                //go to child
                ind=this->index(this->rowCount(ind)-1,0,ind);

                st_current.push(current);
                current=0;


                st_vsego.push(vsego);
                vsego=child_cnt;

                deep++;

            }
            else
            {




             int const_deep=deep;

             for(int i=0;i<const_deep;i++)
             {
               if((current==vsego)&&(deep>0))
               {
                  qDebug()<<"The Last and no children";
                   current=st_current.top();
                   st_current.pop();
                   vsego=st_vsego.top();
                   st_vsego.pop();
                   ind=this->parent(ind);
                   deep--;

               }


             }




            }


/*

            if(!tmpItem->name.isEmpty())
            {

                this->append_item(ind,tmpItem); //надо не добавлять по одиночке к руту


                if(deep>0)
                {
                 int deep_const=deep;


                for(int i=0;i<deep_const;i++)
                {
                    if(deep>0)
                    {
                  //  child_cnt--;


                    if(0>child_cnt)
                        {
                            ind=this->parent(ind);
                            child_cnt=st_cnt.top();
                            st_cnt.pop();
                            deep--;
                            if(child_cnt>0)
                            child_cnt--;
                        }
                    }

                }
                qDebug()<<"deep "<<deep;
                }

                                                //надо собрать дерево и записать указатель на дерево в переменную рута.
            }
            else
                {
                qDebug()<<"tmpItem->name.isEmpty()";
                }

            if (child_cnt>0)
            {


                qDebug()<<"!!! have a child: "<<cnt;


                ind=this->index(this->rowCount(ind)-1,0,ind);
                child_cnt=st_cnt.top();
                deep++;
            }







                */
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

  // QModelIndex root=this.parent(ind);

   MyItem *item = static_cast<MyItem*>(ind.internalPointer());



   if(item->childCount()>0)
   item->show_children_1(&settings,true);

   settings.beginGroup("TREE");
   settings.setValue("Count",ID::getNextID()-1);
   settings.endGroup();

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


















