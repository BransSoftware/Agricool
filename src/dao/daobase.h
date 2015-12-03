#ifndef DAOBASE_H
#define DAOBASE_H

#include <QtSql/QtSql>
#include "src/service/dbService.h"

template <typename T>
class DaoBase : public QSqlTableModel
{
public:
    DaoBase(DbService * parent, QSqlDatabase db);

    QList<T*> getAll();
    T* get(int id);
    void add(T model);
    void update(T model);
    void remove(int id);
    void removeAll();
protected:
    virtual T* fillFromDb(QSqlRecord record) = 0;

    DbService* dbService;
};

template <typename T>
DaoBase<T>::DaoBase(DbService * parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    dbService = parent;
    setEditStrategy(QSqlTableModel::OnRowChange);
}

template <typename T>
QList<T*> DaoBase<T>::getAll()
{
    QList<T*> models;
    QSqlTableModel::select();

    for(int i=0; i < rowCount(); i++)
    {
        models.append(fillFromDb(record(i)));
    }

    return models;
}

template <typename T>
T* DaoBase<T>::get(int id)
{
    query().exec(QString("SELECT * FROM " + tableName() + " WHERE plotID = %1").arg(id));

    if (query().first())
    {
        return fillFromDb(query().record());
    }
    return NULL;
}

template <typename T>
void DaoBase<T>::add(T model)
{

}

template <typename T>
void DaoBase<T>::update(T model)
{

}

template <typename T>
void DaoBase<T>::remove(int id)
{
    QString req = QString("DELETE FROM " + tableName() + " WHERE plotID = %1").arg(id);
    query().exec(req);
}

template <typename T>
void DaoBase<T>::removeAll()
{
    query().exec("DELETE FROM " + tableName());
}

#endif // DAOBASE_H
