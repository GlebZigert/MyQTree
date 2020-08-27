#ifndef SETTINGUTILS_H
#define SETTINGUTILS_H
#include <myitem.h>
#include <QSettings>


class SettingUtils : public QSettings
{
public:
    SettingUtils();
    static QList<MyItem *> loadTree(MyItem * rootItem, QString fileName = "rifx.ini");
};

#endif // SETTINGUTILS_H
