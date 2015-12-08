#ifndef DAOBASE_H
#define DAOBASE_H

#include <QtSql/QtSql>
#include "src/service/dbService.h"

template <typename T>
class DaoBase : public QSqlTableModel
{
public:
    DaoBase(DbService * parent, QSqlDatabase db);

    QList<T*> getAll(bool isRecursive = true);
    T* get(int id, bool isRecursive = true);
    void add(T* model);
    void update(T* model);
    void remove(int id);
    void removeAll();
    int count();
protected:
    virtual T* createFromDb(QSqlRecord record) = 0;
    virtual QString exportToDb(T* model, QHash<QString, QString> &fields) = 0;
    virtual void postGet(T* model) = 0;
    virtual void postAdd(T* model) = 0;
    virtual void postUpdate(T* model) = 0;
    virtual void postDelete(T* model) = 0;

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
QList<T*> DaoBase<T>::getAll(bool isRecursive = true)
{
    QList<T*> models;
    QSqlTableModel::select();

    for(int i=0; i < rowCount(); i++)
    {
        models.append(createFromDb(record(i)));
    }

    if (isRecursive)
    {
        for(T* model : models)
        {
            postGet(model);
        }
    }
    return models;
}

template <typename T>
T* DaoBase<T>::get(int id, bool isRecursive = true)
{
    QString req = QString("SELECT * FROM '" + tableName() + "' WHERE " + primaryKey().fieldName(0) + " = :id");
    qDebug() << "get: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", id);
    if (!q.exec())
    {
        qDebug() << "Error" << q.lastError();
    }

    if (q.first())
    {
        T* model = createFromDb(q.record());
        if (isRecursive)
        {
            postGet(model);
        }

        return model;
    }
    return NULL;
}

template <typename T>
void DaoBase<T>::add(T* model)
{
    QString queryInsert = "INSERT INTO " + tableName() + " (";
    QHash<QString, QString> fields;
    QString primaryKey = exportToDb(model, fields);

    fields.remove(primaryKey);

    for(QString key : fields.keys())
    {
        if (!fields[key].isEmpty())
        {
            queryInsert.append(key).append(",");
        }
    }
    queryInsert.remove(queryInsert.size() - 1, 1);
    queryInsert.append(") VALUES(");

    for(QString value : fields)
    {
        if (!value.isEmpty())
        {
            queryInsert.append(value).append(",");
        }
    }
    queryInsert.remove(queryInsert.size() - 1, 1);
    queryInsert.append(")");

    // Execute query to insert a new row
    query().exec(queryInsert);
}

template <typename T>
void DaoBase<T>::update(T* model)
{
    QString queryUpdate = "UPDATE " + tableName() + " SET ";

    QHash<QString, QString> fields;
    QString primaryKey = exportToDb(model, fields);

    int model_id = fields[primaryKey].toInt();

    fields.remove(primaryKey);

    for(QString key : fields.keys())
    {
        if (!fields[key].isEmpty())
        {
            queryUpdate.append(key).append("=").append(fields[key]).append(",");
        }
    }

    queryUpdate.remove(queryUpdate.size() - 1, 1);
    queryUpdate.append(" WHERE ").append(primaryKey).append("=").append(QString::number(model_id));

    // Execute query to update the given row
    query().exec(queryUpdate);
}

template <typename T>
void DaoBase<T>::remove(int id)
{
    QString req = QString("DELETE FROM " + tableName() + " WHERE " + primaryKey().fieldName(0) + " = %1").arg(id);
    query().exec(req);
}

template <typename T>
void DaoBase<T>::removeAll()
{
    query().exec("DELETE FROM " + tableName());
}

template <typename T>
int DaoBase<T>::count()
{
    query().exec(QString("SELECT COUNT(*) FROM " + tableName()));

    return query().record().value(0).toInt();
}


#endif // DAOBASE_H
