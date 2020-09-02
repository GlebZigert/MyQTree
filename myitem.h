#ifndef MYITEM_H
#define MYITEM_H

#include<QList>
#include <QPixmap>
#include<QSettings>
#include "mynumber.h"
#include "id.h"


enum TypeDevice
      {
        type_CD =  (quint8)11,
        type_IU =(quint8)12,
       type_TG =(quint8)10
      };

class MyItem
{



public:
    MyItem(MyItem *mparent);
     MyItem(MyItem *mparent,QString name, int Type);
    ~MyItem();




   MyItem *m_parent; //родитель
   QList<MyItem*> m_child_list;//список детей

int row() const;
int childCount() const;




   static int number;

   void show_children(QSettings *settings,QString parrent, int cnt);

void show_children_1(QSettings *settings,bool root);

QPixmap viewPXM; //отображаемая иконка
 QPixmap getViewPxm();

 static int ID;

public:

 int Type;//=0
 int Num1;//=0
 int Num2;//=0
 int Num3;//=0
 int Level;//=1
 QString Name;//=250
 int IconVisible;//=0
 int X;//=40
 int Y;//=40
 int DK;//=1
 int Bazalt;//=0
 int Metka;//=0
 int Razriv;//=0
 int AdamOff;//=0
 int AlarmMsgOn;//=0
 int ConnectBlock;//=0
 int OutType;//=0
 int asoosd_kk;//=0
 int asoosd_nn;//=0
 QString Description;//=
 int lan;//=0
 int lon;//=0
 int UdpUse;//=0
 QString UdpAdress;//=
 int UdpPort;//=0
 int Metka1Time_0;//=0
 int Metka1Time_1;//=0
 int Metka2Time_0;//=0
 int Metka2Time_1;//=0
 int Metka3Time_0;//=0
 int Metka3Time_1;//=0
 int Metka4Time_0;//=0
 int Metka4Time_1;//=0
 int MetkaDopuskTime_0;//=0
 int MetkaDopuskTime_1;//=1





};

#endif // MYITEM_H
