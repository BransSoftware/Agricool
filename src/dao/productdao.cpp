#include "productdao.h"

ProductDao::ProductDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Product>(parent, db)
{
    setTable("Product");
}

Product* ProductDao::fillFromDb(QSqlRecord record)
{
    /*return new Product(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        static_cast<QuantityUnit>(record.value(2).toInt()), // unit
        record.value(3).toInt(), // price per quantity
        static_cast<ProductType>(record.value(4).toInt()), // type
        this
    );*/
    return NULL;
}
