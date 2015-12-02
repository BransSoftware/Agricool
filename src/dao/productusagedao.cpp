#include "productusagedao.h"

ProductUsageDao::ProductUsageDao(QObject * parent, QSqlDatabase db)
    : DaoBase<ProductUsage>(parent, db)
{
    setTable("ProductUsage");
}

ProductUsage* ProductUsageDao::fillFromDb(QSqlRecord record)
{
    //return new ProductUsage(record.value(1));
    return NULL;
}
