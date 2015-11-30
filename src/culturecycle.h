#ifndef CULTURECYCLE_H
#define CULTURECYCLE_H

#include <QObject>
#include <QDateTime>
#include <QList>
#include "enums.h"
#include "plot.h"
#include "harvest.h"
#include "event.h"
#include "operation.h"

class Plot;
class Operation;
class Event;
class Harvest;

class CultureCycle : public QObject
{
    Q_OBJECT

public:

    CultureCycle(int id, Plot* p, QString name = QString (tr("Unknown Cycle")), double area = 0, QDateTime startD = QDateTime::currentDateTime(), QDateTime endD = QDateTime(), \
                 bool complete = false, QString com = QString(tr("")), int estimatedC = 0, int estimatedI = 0);
    ~CultureCycle();

    int getCycleID() const;

    const Plot *getCultivatedPlot() const;

    QString getCycleName() const;
    void setCycleName(const QString &value);

    double getInitialAreaSize() const;
    void setInitialAreaSize(double value);

    double getActualCultivatedArea() const;
    void setActualCultivatedArea(double value);

    QDateTime getStartDate() const;
    void setStartDate(const QDateTime &value);

    QDateTime getEndDate() const;
    void setEndDate(const QDateTime &value);

    bool getIsComplete() const;
    void setIsComplete(bool value);

    QList<Operation *> getOperations() const;
    void setOperations(const QList<Operation *> &value);
    void addOperation(const Operation &newOp);

    QList<Event *> getEvents() const;
    void setEvents(const QList<Event *> &value);
    void addEvent(const Event &newEvent);

    QList<Harvest *> getHarvests() const;
    void setHarvests(const QList<Harvest *> &value);
    void addHarvest(const Harvest &newHarvest);

    int getEstimatedCost() const;
    void setEstimatedCost(int value);

    int getEstimatedIncome() const;
    void setEstimatedIncome(int value);

    QString getComment() const;
    void setComment(const QString &value);


private:

    const int cycleID;
    const Plot *cultivatedPlot;
    QString cycleName;
    double initialAreaSize;
    double actualCultivatedArea;// in square meters -  not DB field : initial size + events modification
    QDateTime startDate;
    QDateTime endDate;
    bool isComplete;
    QList<Operation *> operations;
    QList<Event *> events;
    QList<Harvest *> harvests;
    int costSum; // (€) - not DB field - sum from all operations costs and bad events
    int incomeSum; // (€) -  not DB field - sum from harvest selling and good events
    int estimatedCost; // (€) [optional] - the estimation is made at start, and we want to see the difference at the end
    int estimatedIncome; // (€) [optional] - the estimation is made at start, and we want to see the difference at the end
    QString comment;

signals:

public slots:

    void updateValues();

};

#endif // CULTURECYCLE_H
