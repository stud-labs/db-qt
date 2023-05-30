#include "qsqlproctablemodel.h"

QSqlProcTableModel::QSqlProcTableModel()
{
    setEditStrategy(QSqlTableModel::OnRowChange);
}
