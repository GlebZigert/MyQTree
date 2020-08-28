#ifndef MYITEM_H
#define MYITEM_H

#include<QList>
#include <QPixmap>
#include<QSettings>



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

   void show_children(QSettings *settings,QString parrent, int cnt);



QPixmap viewPXM; //отображаемая иконка
 QPixmap getViewPxm();

private:





};

#endif // MYITEM_H
