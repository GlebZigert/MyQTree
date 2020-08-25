#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "myitem.h"
#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

model=new MyModel();


     QFile file(":/default.txt");
      file.open(QIODevice::ReadOnly);
      treemodel=new TreeModel(file.readAll());

      file.close();

      QTreeView *treeView = new QTreeView();
      treeView->setModel(treemodel);
      treeView->setWindowTitle(QObject::tr("Molecules"));
      treeView->show();

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
        this->ui->treeView->setWindowTitle(QObject::tr("Molecules"));
       this->ui->treeView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
