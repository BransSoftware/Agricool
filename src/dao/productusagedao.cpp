#include "productusagedao.h"

ProductUsageDao::ProductUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ProductUsage>(parent, db)
{
    setTable("ProductUsage");
}

ProductUsage* ProductUsageDao::createFromDb(QSqlRecord record)
{
    Operation* operation = dbService->getDao<OperationDao>()->get(record.value(1).toInt());
    Product* product = dbService->getDao<ProductDao>()->get(record.value(2).toInt());
    
    return new ProductUsage(record.value(0).toInt(), // id
        operation, // operation
        product, // product
        record.value(3).toInt() // quantity used
    );
}

QString ProductUsageDao::exportToDb(ProductUsage* model, QHash<QString, QString> &fields)
{
    fields["productUsageID"] = QString::number(model->getProductUsageID());
    fields["operationID"] = QString::number(model->getOperation()->getOperationID());
    fields["productID"] = QString::number(model->getProductUsed()->getProductID());
    fields["productQuantities"] = QString::number(model->getQuantityUsed());
    //fields["productUsageDate"] = model->get();

    return "productUsageID";
}
