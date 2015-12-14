#include "productdao.h"

ProductDao::ProductDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Product>(parent, db)
{
    setTable("Product");
}

Product* ProductDao::createFromDb(QSqlRecord record)
{
    return new Product(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        static_cast<QuantityUnit>(record.value(2).toInt()), // unit
        record.value(3).toInt(), // price per quantity
        static_cast<ProductType>(record.value(4).toInt()), // type
        this
    );
}

QString ProductDao::exportToDb(Product* model, QHash<QString, QString> &fields)
{
    fields["productID"] = QString::number(model->getProductID());
    if (!model->getProductName().isEmpty())
    {
        fields["productName"] = "'" + model->getProductName() + "'";
    }
    fields["quantityUnitSymbol"] = QString::number(static_cast<int>(model->getQuantityUnit()));
    fields["pricePerQuantityUnit"] = QString::number(model->getPricePerQuantityUnit());
    fields["productType"] = QString::number(static_cast<int>(model->getProductType()));

    return "productID";
}
