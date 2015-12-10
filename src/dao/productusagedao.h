#ifndef PRODUCTUSAGEDAO_H
#define PRODUCTUSAGEDAO_H

#include "src/dao/plotdao.h"

class ProductUsageDao : public DaoBase<ProductUsage>
{
public:
    ProductUsageDao(DbService * parent, QSqlDatabase db);
    QList<ProductUsage*> getProductUsageByOperation(Operation* operation);

protected:
    ProductUsage* createFromDb(QSqlRecord record);
    QString exportToDb(ProductUsage* model, QHash<QString, QString> &fields);

private:
    ProductUsage* createFromDb(QSqlRecord record, Operation* operation);
};

#endif // PRODUCTUSAGEDAO_H
