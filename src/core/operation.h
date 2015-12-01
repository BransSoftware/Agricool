#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include "src/core/enums.h"
#include "src/core/tool.h"
#include "src/core/product.h"
#include "src/core/toolusage.h"
#include "src/core/productusage.h"
#include "src/core/culturecycle.h"

class CultureCycle;
class ToolUsage;
class ProductUsage;

class Operation : public QObject
{
    Q_OBJECT
public:

    Operation(int id, CultureCycle* c, QString opName = QString(tr("Unknown Operation")), QDateTime date = QDateTime::currentDateTime(), \
              int dur = 0, int hourCost = 0, OperationType opT = OperationType::Undef, QString com = QString(tr("")));
    ~Operation();

    int getOperationID() const;

    const CultureCycle *getCycle() const;

    QString getOperationName() const;
    void setOperationName(const QString &value);

    QDateTime getOperationDate() const;
    void setOperationDate(const QDateTime &value);

    int getDuration() const;
    void setDuration(int value);

    int getEmployeeWorkHourCost() const;
    void setEmployeeWorkHourCost(int value);

    OperationType getOperationType() const;
    void setOperationType(const OperationType &value);

    QList<ToolUsage *> getToolUsed() const;
    void setToolUsed(const QList<ToolUsage *> &value);

    QList<ProductUsage *> getProductUsed() const;
    void setProductUsed(const QList<ProductUsage *> &value);

    int getOperationCost() const;
    void setOperationCost(int value);

    QString getComment() const;
    void setComment(const QString &value);

private:

    const int operationID;
    const CultureCycle *cycle;
    QString operationName;
    QDateTime operationDate;
    int duration; // (hour)
    int employeeWorkHourCost; // todo add name or employee class - additional cost in case the work is done by an employee
    OperationType operationType;
    QList<ToolUsage *> toolUsed;
    QList<ProductUsage *> productUsed;
    int operationCost; // (€) - not in DB field - sum of products used and tool usage (cost per hour * duration)
    QString comment;

signals:

public slots:

    void updateValues();

};

#endif // OPERATION_H
