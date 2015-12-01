#include "src/core/culturecycle.h"

CultureCycle::CultureCycle(int id, Plot *p, QString name, double area, QDateTime startD, QDateTime endD, bool complete, QString com, int estimatedC, int estimatedI):
    QObject(p), cycleID(id), cycleName(name),  cultivatedPlot(p), initialAreaSize(area), startDate(startD), endDate(endD), isComplete(complete), comment(com), estimatedCost(estimatedC), estimatedIncome(estimatedI)
{

}

int CultureCycle::getCycleID() const
{
    return cycleID;
}

const Plot *CultureCycle::getCultivatedPlot() const
{
    return cultivatedPlot;
}

QString CultureCycle::getCycleName() const
{
    return cycleName;
}

void CultureCycle::setCycleName(const QString &value)
{
    cycleName = value;
}

double CultureCycle::getInitialAreaSize() const
{
    return initialAreaSize;
}

void CultureCycle::setInitialAreaSize(double value)
{
    initialAreaSize = value;
}

QDateTime CultureCycle::getStartDate() const
{
    return startDate;
}

void CultureCycle::setStartDate(const QDateTime &value)
{
    startDate = value;
}

QDateTime CultureCycle::getEndDate() const
{
    return endDate;
}

void CultureCycle::setEndDate(const QDateTime &value)
{
    endDate = value;
}

bool CultureCycle::getIsComplete() const
{
    return isComplete;
}

void CultureCycle::setIsComplete(bool value)
{
    isComplete = value;
}

QList<Operation *> CultureCycle::getOperations() const
{
    return operations;
}

void CultureCycle::setOperations(const QList<Operation *> &value)
{
    operations = value;
}

QList<Event *> CultureCycle::getEvents() const
{
    return events;
}

void CultureCycle::setEvents(const QList<Event *> &value)
{
    events = value;
}

QList<Harvest *> CultureCycle::getHarvests() const
{
    return harvests;
}

void CultureCycle::setHarvests(const QList<Harvest *> &value)
{
    harvests = value;
}

int CultureCycle::getEstimatedCost() const
{
    return estimatedCost;
}

void CultureCycle::setEstimatedCost(int value)
{
    estimatedCost = value;
}

int CultureCycle::getEstimatedIncome() const
{
    return estimatedIncome;
}

void CultureCycle::setEstimatedIncome(int value)
{
    estimatedIncome = value;
}

QString CultureCycle::getComment() const
{
    return comment;
}

void CultureCycle::setComment(const QString &value)
{
    comment = value;
}

double CultureCycle::getActualCultivatedArea() const
{
    return actualCultivatedArea;
}

void CultureCycle::setActualCultivatedArea(double value)
{
    actualCultivatedArea = value;
}

void CultureCycle::updateValues()
{
    //todo update cost, income and acutal size
}

CultureCycle::~CultureCycle()
{

}
