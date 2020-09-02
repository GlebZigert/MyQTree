#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "treemodel.h"
#include "treeitem.h"
#include"mytreeview.h"
#include "mymodel.h"
#include "myitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    TreeModel *treemodel;
    MyModel *model;

   const QModelIndex *current_index;

   bool val;

   QString path;

private slots:



    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();




    void on_treeView_activated(const QModelIndex &index);

    void on_treeView_entered(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_action_2_triggered();



    void on_action_triggered();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_change_item_clicked();



   bool change_item(MyItem *item);


    bool Get_data();

    bool Get_CD_data();

    bool Get_IU_data();

    bool Get_TG_data();

    void on_action_3_triggered();

private:

    Ui::MainWindow *ui;

    int Type;
    QString name;

    int Num1;
    int Num2;
    bool DK;
    bool basalt;
    bool connectBlock;
    bool UdpUse;
      QString UdpAdress;
      int UdpPort;

      bool ok;

   bool  CD_look_on_input_data();








public slots:

    void expand_all(void);


};

#endif // MAINWINDOW_H
