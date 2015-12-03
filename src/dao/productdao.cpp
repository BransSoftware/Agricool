#include "productdao.h"

ProductDao::ProductDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Product>(parent, db)
{
    setTable("Product");
}

Product* ProductDao::fillFromDb(QSqlRecord record)
{
    //return new Product(record.value(1));
    return NULL;
}
