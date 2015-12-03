#ifndef PRODUCTDAO_H
#define PRODUCTDAO_H

#include "src/dao/plotdao.h"

class ProductDao : public DaoBase<Product>
{
public:
    ProductDao(DbService * parent, QSqlDatabase db);
    Product* createFromDb(QSqlRecord record);
    QString exportToDb(Product* model, QHash<QString, QString> &fields);
};

#endif // PRODUCTDAO_H
