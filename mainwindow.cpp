#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./departmentlistdialog.h"
#include <QMessageBox>
#include "./db.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbOk = SetupDatabaseConnection(db);
    if (! dbOk) {
      QMessageBox::critical(this,
                            "Cannot connect to DB",
                            "Sonething wrong with DB connection, may be password? (DBPASSWD)");
      reject();
    } else {
      on_pushButton_clicked();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // QMessageBox::warning(nullptr, "It works", QString("Hello!"));
    DepartmentListDialog dep(this);
    dep.show();
    dep.exec();
}


void MainWindow::on_buttonBox_accepted()
{
    accept();
}

