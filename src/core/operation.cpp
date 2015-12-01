#include "src/core/operation.h"

Operation::Operation(int id, CultureCycle *c, QString opName, QDateTime date, int dur, int hourCost, OperationType opT, QString com) :
    QObject(c), operationID(id), cycle(c), operationName(opName), operationDate(date), duration(dur), employeeWorkHourCost(hourCost), operationType(opT), comment(com)
{
    operationCost = duration * employeeWorkHourCost;
}

int Operation::getOperationID() const
{
    return operationID;
}

const CultureCycle *Operation::getCycle() const
{
    return cycle;
}

QString Operation::getOperationName() const
{
    return operationName;
}

void Operation::setOperationName(const QString &value)
{
    operationName = value;
}

QDateTime Operation::getOperationDate() const
{
    return operationDate;
}

void Operation::setOperationDate(const QDateTime &value)
{
    operationDate = value;
}

int Operation::getDuration() const
{
    return duration;
}

void Operation::setDuration(int value)
{
    duration = value;
}

int Operation::getEmployeeWorkHourCost() const
{
    return employeeWorkHourCost;
}

void Operation::setEmployeeWorkHourCost(int value)
{
    employeeWorkHourCost = value;
}

OperationType Operation::getOperationType() const
{
    return operationType;
}

void Operation::setOperationType(const OperationType &value)
{
    operationType = value;
}

QList<ToolUsage *> Operation::getToolUsed() const
{
    return toolUsed;
}

void Operation::setToolUsed(const QList<ToolUsage *> &value)
{
    toolUsed = value;
}

QList<ProductUsage *> Operation::getProductUsed() const
{
    return productUsed;
}

void Operation::setProductUsed(const QList<ProductUsage *> &value)
{
    productUsed = value;
}

int Operation::getOperationCost() const
{
    return operationCost;
}

void Operation::setOperationCost(int value)
{
    operationCost = value;
}

QString Operation::getComment() const
{
    return comment;
}

void Operation::setComment(const QString &value)
{
    comment = value;
}

void Operation::updateValues()
{
    //todo : update operation Cost
}

Operation::~Operation()
{

}










