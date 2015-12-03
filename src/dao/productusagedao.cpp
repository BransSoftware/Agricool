#include "productusagedao.h"

ProductUsageDao::ProductUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ProductUsage>(parent, db)
{
    setTable("ProductUsage");
}

ProductUsage* ProductUsageDao::fillFromDb(QSqlRecord record)
{
    /*Operation* operation = dbService->getDao<OperationDao>()->get(record.value(1).toInt());
    Product* product = dbService->getDao<ProductDao>()->get(record.value(2).toInt());
    
    return new ProductUsage(record.value(0).toInt(), // id
        operation, // operation
        product, // product
        record.value(3).toInt() // quantity used
    );*/
    return NULL;
}
