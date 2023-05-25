#include "departmentlistdialog.h"
#include "ui_departmentlistdialog.h"

DepartmentListDialog::DepartmentListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepartmentListDialog)
{
    ui->setupUi(this);
    setupResult();
}

DepartmentListDialog::~DepartmentListDialog()
{
    delete ui;
}

void DepartmentListDialog::setupResult() {

}
