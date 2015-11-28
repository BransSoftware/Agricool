#ifndef BDDSERVICE_H
#define BDDSERVICE_H

#include <QtSql/QtSql>

class BddService
{
public :
    BddService();
    ~BddService();

    void executeQuery(QString request);

private:
    QSqlDatabase db;
};

#endif
