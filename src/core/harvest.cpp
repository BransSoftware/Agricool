#include "src/core/harvest.h"


Harvest::Harvest(int id, CultureCycle *c, QString name, int q, int incPQU, QuantityUnit qU, QString com) :
    QObject(c), harvestID(id), cycle(c), plantName(name), quantity(q), incomePerQuantityUnit(incPQU), quantityUnit(qU), qualityComment(com)
{

}

int Harvest::getHarvestID() const
{
    return harvestID;
}

const CultureCycle *Harvest::getCycle() const
{
    return cycle;
}

QString Harvest::getPlantName() const
{
    return plantName;
}

void Harvest::setPlantName(const QString &value)
{
    plantName = value;
}
int Harvest::getQuantity() const
{
    return quantity;
}

void Harvest::setQuantity(int value)
{
    quantity = value;
}
int Harvest::getIncomePerQuantityUnit() const
{
    return incomePerQuantityUnit;
}

void Harvest::setIncomePerQuantityUnit(int value)
{
    incomePerQuantityUnit = value;
}

QuantityUnit Harvest::getQuantityUnit() const
{
    return quantityUnit;
}

void Harvest::setQuantityUnit(const QuantityUnit &value)
{
    quantityUnit = value;
}

QString Harvest::getQualityComment() const
{
    return qualityComment;
}

void Harvest::setQualityComment(const QString &value)
{
    qualityComment = value;
}

Harvest::~Harvest(){}






