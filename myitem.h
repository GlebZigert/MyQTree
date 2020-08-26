#ifndef MYITEM_H
#define MYITEM_H

#include<QList>



class MyItem
{



public:
    MyItem(MyItem *mparent);
    ~MyItem();




   MyItem *m_parent; //родитель
   QList<MyItem*> m_child_list;//список детей

int row() const;
int childCount() const;

   QString name;
   QString type;




private:





};

#endif // MYITEM_H
