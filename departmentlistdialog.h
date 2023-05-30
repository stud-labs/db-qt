#ifndef DEPARTMENTLISTDIALOG_H
#define DEPARTMENTLISTDIALOG_H

#include <QDialog>
#include "qsqlproctablemodel.h"

namespace Ui {
class DepartmentListDialog;
}

class DepartmentListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepartmentListDialog(QWidget *parent = nullptr);
    ~DepartmentListDialog();

private:
    Ui::DepartmentListDialog *ui;

protected:
    virtual void setupResult();
    QSqlProcTableModel tableModel;
};

#endif // DEPARTMENTLISTDIALOG_H
