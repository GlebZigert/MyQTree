#include "myitem.h"
#include<QDebug>






MyItem::MyItem(MyItem *mparent)
{
    this->m_parent=mparent;
}

MyItem::~MyItem()
{
    qDebug()<<"delete Item"<<this->name;
qDeleteAll( m_child_list);
}

int MyItem::row() const
{
    if (m_parent)
        return m_parent->m_child_list.indexOf(const_cast<MyItem*>(this));
}

int MyItem::childCount() const
{
    return this->m_child_list.count();
}




