//
// Created by Barry E. Moore II on 8/8/16.
//

#include "mytreeview.h"
#include <QDebug>

MyTreeView::MyTreeView(QTreeView *parent)
  : QTreeView(parent)
{
  connect(this, SIGNAL(clicked(QModelIndex)), SLOT(onClick(QModelIndex)));
}

void MyTreeView::onClick(QModelIndex index)
{
  qDebug() << index.data(Qt::DisplayRole).toString() << '\n';

  if (index.column() == 0) {
    qDebug() << "Switch Molecule!\n";
  }
  else if (index.column() == 1) {
    qDebug()  << "Delete Molecule!\n";
  }
}