#include "productusagedao.h"

ProductUsageDao::ProductUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ProductUsage>(parent, db)
{
    setTable("ProductUsage");
}

ProductUsage* ProductUsageDao::createFromDb(QSqlRecord record)
{
    return createFromDb(record, NULL);
}

ProductUsage* ProductUsageDao::createFromDb(QSqlRecord record, Operation* operation)
{
    if (operation == NULL)
    {
        operation= dbService->getDao<OperationDao>()->get(record.value(1).toInt());
    }

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

QList<ProductUsage*> ProductUsageDao::getProductUsageByOperation(Operation* operation)
{
    QList<ProductUsage*> productUsages;
    QString req = QString("SELECT * FROM " + tableName() + " WHERE operationID=:id");
    qDebug() << "ProductUsageDao::getProductUsageByOperation: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", operation->getOperationID());
    if (!q.exec())
    {
        qWarning() << q.lastError();
    }

    while (q.next())
    {
        ProductUsage* productUsage = createFromDb(q.record(), operation);
        postGet(productUsage);
        productUsages.append(productUsage);
    }

    return productUsages;
}

void ProductUsageDao::postGet(ProductUsage* model)
{
}

void ProductUsageDao::postAdd(ProductUsage* model)
{
}

void ProductUsageDao::postUpdate(ProductUsage* model)
{
}

void ProductUsageDao::postDelete(ProductUsage* model)
{
}
