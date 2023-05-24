#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./departmentlistdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_clicked();
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

