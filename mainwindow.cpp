#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    this->current_index=nullptr;

model=new MyModel();

connect(this->model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),
        this, SLOT(expand_all()));

/*
     QFile file(":/default.txt");
      file.open(QIODevice::ReadOnly);
      treemodel=new TreeModel(file.readAll());

      file.close();

      QTreeView *treeView = new QTreeView();
      treeView->setModel(treemodel);
      treeView->setWindowTitle(QObject::tr("Molecules"));
      treeView->show();*/

//    model.data(model.index(0, 0), Qt::DisplayRole);


/*
        qDebug()<<"rowcount: "<<model.rowCount();
        qDebug()<<"colomncount: "<<model.columnCount();

    for(int row=0;row<model.rowCount();row++)
    {
        QVariant data=model.data(model.index(0, row), Qt::EditRole);

        qDebug()<<"data: "<<data.toString();

    }

*/
//
    /*

*/

       this->ui->treeView->setModel(model);
 this->ui->treeView->expandAll();
this->ui->treeView->setColumnHidden(1, true);

 //       this->ui->treeView->setWindowTitle(QObject::tr("Molecules"));
 //      this->ui->treeView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    current_index=&index;
QModelIndex ind_name=model->index(index.row(),0,index.parent());
QModelIndex ind_type=model->index(index.row(),1,index.parent());
QString name=model->data(ind_name, Qt::DisplayRole).toString();;
QString type=model->data(ind_type, Qt::DisplayRole).toString();
qDebug()<<name;
qDebug()<<type;
this->ui->lineEdit->setText(name);
this->ui->lineEdit_2->setText(type);
this->ui->lineEdit_3->setText(QString::number(model->rowCount(index)));
}

void MainWindow::on_pushButton_clicked()
{


    qDebug()<<"treePosition(); "<<this->ui->treeView->treePosition();
    int res=1;


    QModelIndex current=this->ui->treeView->currentIndex();



    if (current_index==nullptr)
    {
        res=0;
    qDebug()<<"no current index!!!";
    }


    QString name=ui->name_item_to_append->text();
     QString type=ui->type_item_to_append->text();
     qDebug()<<name;
      qDebug()<<type;
      if(name=="")
      {
          res=0;
      qDebug()<<"empty name!!";
      }

      if(type=="")
      {
       res=0;
      qDebug()<<"empty type!!";
      }

      if(1==res)
      {
          MyItem *item=new MyItem(nullptr);
          item->name=name;
          item->type=type;
          model->append_item(model->index(current.row(),0,current.parent()),item);



         this->ui->treeView->setCurrentIndex(model->index(current.row(),0,current.parent()));
      }



}











void MainWindow::on_pushButton_2_clicked()
{
    QModelIndex current=this->ui->treeView->currentIndex();
    model->delete_item(model->index(current.row(),0,current.parent()));

}

void MainWindow::on_pushButton_3_clicked()
{
    this->ui->treeView->expandAll();

}

void MainWindow::expand_all()
{
    qDebug()<<"expand_all";
    this->ui->treeView->expandAll();

}

void MainWindow::on_treeView_activated(const QModelIndex &index)
{
    qDebug()<<"activated";
}

void MainWindow::on_treeView_entered(const QModelIndex &index)
{
    qDebug()<<"entered";
}
