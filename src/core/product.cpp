#include "src/core/product.h"

Product::Product(int id, QString name, QuantityUnit unit, int ppq, ProductType t, QObject *parent) :
    QObject(parent), productID(id), productName(name), quantityUnit(unit), pricePerQuantityUnit(ppq), productType(t)
{

}

int Product::getProductID() const
{
    return productID;
}

QString Product::getProductName() const
{
    return productName;
}

void Product::setProductName(const QString &value)
{
    productName = value;
}

QuantityUnit Product::getQuantityUnit() const
{
    return quantityUnit;
}

void Product::setQuantityUnit(const QuantityUnit &value)
{
    quantityUnit = value;
}
int Product::getPricePerQuantityUnit() const
{
    return pricePerQuantityUnit;
}

void Product::setPricePerQuantityUnit(int value)
{
    pricePerQuantityUnit = value;
}

ProductType Product::getProductType() const
{
    return productType;
}

void Product::setProductType(const ProductType &value)
{
    productType = value;
}

Product::~Product()
{

}



