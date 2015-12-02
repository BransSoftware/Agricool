#include "productdao.h"

ProductDao::ProductDao(QObject * parent, QSqlDatabase db)
    : DaoBase<Product>(parent, db)
{
    setTable("Product");
}

Product* ProductDao::fillFromDb(QSqlRecord record)
{
    //return new Product(record.value(1));
    return NULL;
}
