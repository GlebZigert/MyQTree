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

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
