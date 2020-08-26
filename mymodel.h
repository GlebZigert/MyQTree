#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include "myitem.h"
#include <QModelIndex>
#include<QAbstractItemModel>

class MyModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = 0);
    ~MyModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    bool append_item(const QModelIndex &index, MyItem *item);


private:

    MyItem *rootItem;

signals:
    void dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
};

#endif // MYMODEL_H
