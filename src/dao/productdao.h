#ifndef PRODUCTDAO_H
#define PRODUCTDAO_H

#include "src/dao/plotdao.h"

class ProductDao : public DaoBase<Product>
{
public:
    ProductDao(QObject * parent, QSqlDatabase db);
    Product* fillFromDb(QSqlRecord record);
};

#endif // PRODUCTDAO_H
