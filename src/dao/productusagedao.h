#ifndef PRODUCTUSAGEDAO_H
#define PRODUCTUSAGEDAO_H

#include "src/dao/plotdao.h"

class ProductUsageDao : public DaoBase<ProductUsage>
{
public:
    ProductUsageDao(DbService * parent, QSqlDatabase db);
    ProductUsage* createFromDb(QSqlRecord record);
    QString exportToDb(ProductUsage* model, QHash<QString, QString> &fields);
};

#endif // PRODUCTUSAGEDAO_H
