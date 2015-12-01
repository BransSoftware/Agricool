#include "event.h"

Event::Event(int id, CultureCycle *c, int inc, int cost, int areaGain, int areaLost, QString desc ) :
    QObject(c), eventID(id), cycle(c), financialIncome(inc), financialCost(cost), actualAreaGained(areaGain), actualAreaLost(areaLost), eventDescription(desc)
{

}

int Event::getEventID() const
{
    return eventID;
}

const CultureCycle *Event::getCycle() const
{
    return cycle;
}

int Event::getFinancialIncome() const
{
    return financialIncome;
}

void Event::setFinancialIncome(int value)
{
    financialIncome = value;
}

int Event::getFinancialCost() const
{
    return financialCost;
}

void Event::setFinancialCost(int value)
{
    financialCost = value;
}

int Event::getActualAreaGained() const
{
    return actualAreaGained;
}

void Event::setActualAreaGained(int value)
{
    actualAreaGained = value;
}

int Event::getActualAreaLos() const
{
    return actualAreaLost;
}

void Event::setActualAreaLos(int value)
{
    actualAreaLost = value;
}

QString Event::getEventDescription() const
{
    return eventDescription;
}

void Event::setEventDescription(const QString &value)
{
    eventDescription = value;
}

Event::~Event(){}

