#ifndef PRODUCTUSAGEDAO_H
#define PRODUCTUSAGEDAO_H

#include "src/dao/plotdao.h"

class ProductUsageDao : public DaoBase<ProductUsage>
{
public:
    ProductUsageDao(DbService * parent, QSqlDatabase db);
    ProductUsage* fillFromDb(QSqlRecord record);
};

#endif // PRODUCTUSAGEDAO_H
