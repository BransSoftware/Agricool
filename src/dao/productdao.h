#ifndef PRODUCTDAO_H
#define PRODUCTDAO_H

#include "src/dao/plotdao.h"

class ProductDao : public DaoBase<Product>
{
public:
    ProductDao(DbService * parent, QSqlDatabase db);
protected:
    Product* createFromDb(QSqlRecord record);
    QString exportToDb(Product* model, QHash<QString, QString> &fields);
    void postGet(Product* model);
    void postAdd(Product* model);
    void postUpdate(Product* model);
    void postDelete(Product* model);
};

#endif // PRODUCTDAO_H
