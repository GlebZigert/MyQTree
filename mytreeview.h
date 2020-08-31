//
// Created by Barry E. Moore II on 8/8/16.
//

#ifndef THING_MYTREEVIEW_H
#define THING_MYTREEVIEW_H

#include <QTreeView>

class MyTreeView : public QTreeView {

  Q_OBJECT

  public:
    MyTreeView(QTreeView *parent = 0);

  private slots:
    void onClick(QModelIndex);
};


#endif //THING_MYTREEVIEW_H
