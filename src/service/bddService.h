#ifndef BDDSERVICE_H
#define BDDSERVICE_H

#include <QObject>
#include <QtSql/QtSql>
#include "../dao/plotdao.h"

class BddService : public QObject
{
    Q_OBJECT

public :

    BddService(QObject * parent = 0);
    ~BddService();
    void createSchema();

    template <typename T>
    inline T* getDao()
    {
        for(int i=0; i < models.size(); i++)
        {
            T* model = dynamic_cast<T*>(models.at(i));
            if (model)
            {
                return model;
            }
        }
        return NULL;
    }

private:
    QSqlDatabase db;
    QList<QSqlTableModel*> models;
};

#endif
