#include "departmentlistdialog.h"
#include "ui_departmentlistdialog.h"
#include "qsqlproctablemodel.h"

class DepartmentModel:public QSqlProcTableModel {
public:
    DepartmentModel()
        :  QSqlProcTableModel() {
        setDeleteQuery("call \"DELETE_DEPARTMENT\"(UUID(:number))");
        setUpdateQuery("call \"UPDATE_DEPARTMENT\"(UUID(:number), ':name')");
        setInsertQuery("call \"INSERT_DEPARTMENT\"(UUID(:number), ':name')");
    };
};

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
    tableModel.setTable("department");
    tableModel.select();
    ui->resultView->setModel( &tableModel );
    ui->resultView->hideColumn(0);
}
