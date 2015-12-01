#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <QString>
#include "src/core/enums.h"


class Product : public QObject
{
    Q_OBJECT
public:

    Product(int id, QString name, QuantityUnit unit = QuantityUnit::Undef, int ppq = 0, ProductType t = ProductType::Undef, QObject *parent = 0);
    ~Product();

    int getProductID() const;

    QString getProductName() const;
    void setProductName(const QString &value);

    QuantityUnit getQuantityUnit() const;
    void setQuantityUnit(const QuantityUnit &value);

    int getPricePerQuantityUnit() const;
    void setPricePerQuantityUnit(int value);

    ProductType getProductType() const;
    void setProductType(const ProductType &value);

private:

    const int productID;
    QString productName;
    QuantityUnit quantityUnit;
    int pricePerQuantityUnit; // (€)
    ProductType productType; // [optional]

signals:

public slots:

};

#endif // PRODUCT_H
