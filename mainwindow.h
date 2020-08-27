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

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();




    void on_treeView_activated(const QModelIndex &index);

    void on_treeView_entered(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

public slots:

    void expand_all(void);


};

#endif // MAINWINDOW_H
