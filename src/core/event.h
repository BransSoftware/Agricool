#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QString>
#include "src/core/culturecycle.h"

class CultureCycle;

class Event : public QObject
{
    Q_OBJECT
public:

    Event(int id, CultureCycle* c, int inc = 0, int cost = 0, int areaGain = 0, int areaLost = 0, QString desc = QString(tr("")));
    ~Event();

    int getEventID() const;

    const CultureCycle *getCycle() const;

    int getFinancialIncome() const;
    void setFinancialIncome(int value);

    int getFinancialCost() const;
    void setFinancialCost(int value);

    int getActualAreaGained() const;
    void setActualAreaGained(int value);

    int getActualAreaLos() const;
    void setActualAreaLos(int value);

    QString getEventDescription() const;
    void setEventDescription(const QString &value);

private:

    const int eventID;
    const CultureCycle *cycle;
    int financialIncome; // (€)
    int financialCost; // (€)
    int actualAreaGained; // (m²)
    int actualAreaLost; // (m²)
    QString eventDescription;
signals:

public slots:

};

#endif // EVENT_H
