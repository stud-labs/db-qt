#ifndef QSQLPROCTABLEMODEL_H
#define QSQLPROCTABLEMODEL_H

#include <QSqlTableModel>
#include <QString>
#include <QSqlQuery>

class QSqlProcTableModel : public QSqlTableModel
{
protected:
    QString updateQuery;
    QString insertQuery;
    QString deleteQuery;
public:
    QSqlProcTableModel();
    void setUpdateQuery(QString mQuery) {updateQuery = mQuery;};
    void setInsertQuery(QString mQuery) {insertQuery = mQuery;};
    void setDeleteQuery(QString mQuery) {deleteQuery = mQuery;};
};

#endif // QSQLPROCTABLEMODEL_H
