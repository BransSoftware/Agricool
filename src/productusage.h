#ifndef PRODUCTUSAGE_H
#define PRODUCTUSAGE_H

#include <QObject>
#include "product.h"
#include "operation.h"

class Operation;

class ProductUsage : public QObject
{
    Q_OBJECT

public:

    ProductUsage(int id, Operation* op, Product* product, int quantity =0);
    ~ProductUsage();

    int getProductUsageID() const;

    const Operation *getOperation() const;

    Product *getProductUsed() const;
    void setProductUsed(Product *value);

    int getQuantityUsed() const;
    void setQuantityUsed(int value);

private:

    const int productUsageID;
    const Operation *operation;
    Product *productUsed;
    int quantityUsed; // (unit is the one coming from Product) - todo : allow usage of other quantity unit that product definition


signals:

public slots:

};

#endif // PRODUCTUSAGE_H
