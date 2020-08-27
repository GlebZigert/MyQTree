#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QComboBox>
#include <QListWidget>

#include <QWidget>

class ItemWidget:public QWidget
{
    Q_OBJECT
public:
    ItemWidget(QWidget *parent):QWidget(parent);

QComboBox *combo;
QListWidget *list;

};

#endif // ITEMWIDGET_H
