#include "productusage.h"

ProductUsage::ProductUsage(int id, Operation *op, Product *product, int quantity):
    QObject(op), productUsageID(id), operation(op), productUsed(product), quantityUsed(quantity)
{

}

int ProductUsage::getProductUsageID() const
{
    return productUsageID;
}
const Operation *ProductUsage::getOperation() const
{
    return operation;
}

Product *ProductUsage::getProductUsed() const
{
    return productUsed;
}

void ProductUsage::setProductUsed(Product *value)
{
    productUsed = value;
}
int ProductUsage::getQuantityUsed() const
{
    return quantityUsed;
}

void ProductUsage::setQuantityUsed(int value)
{
    quantityUsed = value;
}

ProductUsage::~ProductUsage()
{

}

