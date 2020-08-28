#include "myitem.h"
#include<QDebug>






MyItem::MyItem(MyItem *mparent)
{
    this->viewPXM=QPixmap(":/icons/SO_green_20x20.png");


    this->m_parent=mparent;

    this->m_child_list.clear();
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

void MyItem::show_children(QSettings *settings,QString parrent, int cnt)
{
    qDebug()<<"---------";
    qDebug()<<this->name;
    qDebug()<<this->type;

    QString strGroup;
    strGroup.clear();
    strGroup.append(parrent);
    strGroup.append("__");
    strGroup.append("Obj-%1");
     strGroup=strGroup.arg(cnt+1);
     qDebug()<<"strGroup"<<strGroup;
     settings->setIniCodec( "Windows-1251" );
     settings->beginGroup(strGroup);
     settings->setValue("Name",this->name);
     settings->setValue("Type",this->type);

qDebug()<<"Count "<<this->m_child_list.count();
    if(this->m_child_list.count()>0)
    {
        settings->setValue("Count",this->m_child_list.count());

        settings->endGroup();

        for(int i=0;i<this->m_child_list.count();i++)
        {
            qDebug()<<"["<<i<<"]";

           qDebug()<<"!!!"<<this->m_child_list.at(i)->childCount();
         this->m_child_list.at(i)->show_children(settings,strGroup,i);
            qDebug()<<"---------";
        }

    }
    else
        settings->endGroup();


}

QPixmap MyItem::getViewPxm()
{

    return  viewPXM;
}




