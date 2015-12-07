#ifndef DAOFACTORY_H
#define DAOFACTORY_H

#include <QObject>
#include <QtSql/QtSql>

class DaoFactory: public QObject
{
    Q_OBJECT

public:
    DaoFactory(QObject * parent, QSqlDatabase db);

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

#endif // DAOFACTORY_H
