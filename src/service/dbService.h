#ifndef BDDSERVICE_H
#define BDDSERVICE_H

#include <QObject>
#include <QtSql/QtSql>
#include "src/dao/daofactory.h"

class DbService : public QObject
{
    Q_OBJECT

public :
    DbService(QObject * parent = 0);
    ~DbService();

    template <typename T>
    inline T* getDao()
    {
        return daoFactory->getDao<T>();
    }

private:
    QSqlDatabase db;
    DaoFactory *daoFactory;

    void createSchema();
    void createData();
};

#endif
