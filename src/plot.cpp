#include "plot.h"

Plot::Plot(int id, QString name, double s, bool ow, int rent, QString com, SubjectiveQuality sq, SubjectiveQuality wd, SubjectiveFrequency rq, \
           SubjectiveFrequency ar, SubjectiveFrequency cr, QObject *parent) :
    QObject(parent), plotID(id), plotName(name), size(s), isOwned(ow), yearlyRent(rent), comment(com), soilQuality(sq), waterDrainage(wd), rocksQuantity(rq), animalDamageRisks(ar), climateDamageRisks(cr)
{

}

int Plot::getPlotID() const
{
    return plotID;
}

QString Plot::getPlotName() const
{
    return plotName;
}

void Plot::setPlotName(const QString &value)
{
    plotName = value;
}

double Plot::getSize() const
{
    return size;
}

void Plot::setSize(double value)
{
    size = value;
}

bool Plot::getIsOwned() const
{
    return isOwned;
}

void Plot::setIsOwned(bool value)
{
    isOwned = value;
}

int Plot::getYearlyRent() const
{
    return yearlyRent;
}

void Plot::setYearlyRent(int value)
{
    yearlyRent = value;
}

QList<CultureCycle *> Plot::getCultureCycles() const
{
    return cultureCycles;
}

void Plot::setCultureCycles(const QList<CultureCycle *> &value)
{
    cultureCycles = value;
}

QString Plot::getComment() const
{
    return comment;
}

void Plot::setComment(const QString &value)
{
    comment = value;
}

SubjectiveQuality Plot::getSoilQuality() const
{
    return soilQuality;
}

void Plot::setSoilQuality(const SubjectiveQuality &value)
{
    soilQuality = value;
}

SubjectiveQuality Plot::getWaterDrainage() const
{
    return waterDrainage;
}

void Plot::setWaterDrainage(const SubjectiveQuality &value)
{
    waterDrainage = value;
}

SubjectiveFrequency Plot::getRocksQuantity() const
{
    return rocksQuantity;
}

void Plot::setRocksQuantity(const SubjectiveFrequency &value)
{
    rocksQuantity = value;
}

SubjectiveFrequency Plot::getAnimalDamageRisks() const
{
    return animalDamageRisks;
}

void Plot::setAnimalDamageRisks(const SubjectiveFrequency &value)
{
    animalDamageRisks = value;
}

SubjectiveFrequency Plot::getClimateDamageRisks() const
{
    return climateDamageRisks;
}

void Plot::setClimateDamageRisks(const SubjectiveFrequency &value)
{
    climateDamageRisks = value;
}

Plot::~Plot()
{

}











