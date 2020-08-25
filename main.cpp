#include "mainwindow.h"
#include <QApplication>
#include"mytreeview.h"
#include <QDebug>
#include "myitem.h"
#include "mymodel.h"
#include <QFileSystemModel>

int main(int argc, char *argv[])
{



   QApplication a(argc, argv);



/*
   QFile file(":/default.txt");
     file.open(QIODevice::ReadOnly);
     TreeModel model(file.readAll());
     file.close();


*/






   /*
   QModelIndex index=model->index(0,0);
//-----------------------------------------------
   if(index.isValid())
   {
        qDebug()<<"[index +]";
   }
   else
   {
     qDebug()<<"[index -]";
   }
//-----------------------------------------------
   MyItem *item = static_cast<MyItem*>(index.internalPointer());
   if(item)
   {
        qDebug()<<"[item +]";
   }
   else
   {
     qDebug()<<"[item -]";
   }
//-----------------------------------------------


   qDebug()<<"[1]";

   qDebug()<<"Name "<<item->name;

qDebug()<<"[2]";
//-----------------------------------------------
qDebug()<<"model->data column 0 "<<model->data(model->index(0,0),Qt::DisplayRole).toString();
qDebug()<<"model->data column 1 "<<model->data(model->index(0,1),Qt::DisplayRole).toString();




QModelIndex next_index=model->index(0,0,index);
if(next_index.isValid())
{
     qDebug()<<"[next_index +]";
}
else
{
  qDebug()<<"[next_index -]";
}

qDebug()<<"model->data column 0 "<<model->data(model->index(0,0,index),Qt::DisplayRole).toString();
qDebug()<<"model->data column 1 "<<model->data(model->index(0,1,index),Qt::DisplayRole).toString();


QModelIndex parent_index=model->parent(next_index);

if(parent_index.isValid())
{
     qDebug()<<"[parent_index +]";
}
else
{
  qDebug()<<"[parent_index -]";
}

qDebug()<<"model->data column 0 "<<model->data(parent_index,Qt::DisplayRole).toString();
qDebug()<<"model->data column 1 "<<model->data(parent_index,Qt::DisplayRole).toString();

qDebug()<<"model->rowCount(model->index(0,0)) "<<model->rowCount(model->index(0,0));
qDebug()<<"model->rowCount(index) "<<model->rowCount(index);
qDebug()<<"model->rowCount(next_index) "<<model->rowCount(next_index);

*/


//qDebug()<<"model->rowCount(model->index(0,0)) "<<model->rowCount(model->index(0,0));
//qDebug()<<"model->rowCount(index) "<<model->rowCount(index);
//qDebug()<<"model->rowCount(next_index) "<<model->rowCount(next_index);

//qDebug()<<"model->data column 0 "<<model->data(model->index(3,0),Qt::DisplayRole).toString();
//qDebug()<<"model->data column 1 "<<model->data(model->index(3,1),Qt::DisplayRole).toString();


//index=model->parent(model->index(0,0));
//QModelIndex parent_index=model->parent(model->index(0,0,index));





//qDebug()<<"model->data column 0 "<<model->data(parent_index,Qt::DisplayRole).toString();
//qDebug()<<"model->data column 1 "<<model->data(parent_index,Qt::DisplayRole).toString();

    /*QModelIndex parent=index;


    index= model.index(i,0,parent);

     qDebug()<<i<<" "<<model.data(index,Qt::DisplayRole).toString();

     index= model.index(0,0,parent);





     }

*/

//MyTreeView *treeView = new MyTreeView();
//treeView->setModel(&model);
//treeView->setWindowTitle(QObject::tr("Molecules"));
//treeView->show();
/*
     MyTreeView *treeView = new MyTreeView();
     treeView->setModel(&model);
     treeView->setWindowTitle(QObject::tr("Molecules"));
     treeView->show();
*/

   /*
    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel model(file.readAll());
    file.close();

    QTreeView *treeView = new QTreeView();
    treeView->setModel(&model);
    treeView->setWindowTitle(QObject::tr("Molecules"));
    treeView->show();

*/




    MainWindow w;
    w.show();



    return a.exec();
}
