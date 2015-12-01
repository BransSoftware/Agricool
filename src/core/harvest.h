#ifndef HARVEST_H
#define HARVEST_H

#include <QObject>
#include <QString>
#include "src/core/culturecycle.h"

class CultureCycle;

class Harvest : public QObject
{
    Q_OBJECT
public:

    Harvest(int id, CultureCycle *c, QString name = QString(tr("Unknown plant")), int q = 0, int incPQU = 0, QuantityUnit qU = QuantityUnit::Undef, QString com = QString(tr("")) );
    ~Harvest();

    int getHarvestID() const;

    const CultureCycle *getCycle() const;

    QString getPlantName() const;
    void setPlantName(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

    int getIncomePerQuantityUnit() const;
    void setIncomePerQuantityUnit(int value);

    QuantityUnit getQuantityUnit() const;
    void setQuantityUnit(const QuantityUnit &value);

    QString getQualityComment() const;
    void setQualityComment(const QString &value);

private:

    const int harvestID;
    const CultureCycle *cycle;
    QString plantName; // - Strings might be predefined (Wheat, Corn, Soybean, etc)
    int quantity;
    int incomePerQuantityUnit; // (€)
    QuantityUnit quantityUnit; // - Strings might be predefined (kg, ton, m3, etc)_
    QString qualityComment; // Might also be predefined, in accordance with harvested products

signals:

public slots:

};

#endif // HARVEST_H
