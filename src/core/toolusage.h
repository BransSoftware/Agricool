#ifndef TOOLUSAGE_H
#define TOOLUSAGE_H

#include <QObject>
#include "src/core/operation.h"
#include "src/core/tool.h"

class Operation;

class ToolUsage : public QObject
{
    Q_OBJECT
public:

    ToolUsage(int id, Operation* op, Tool* tool, int duration = 0);
    ~ToolUsage();

    int getToolUsageID() const;

    const Operation *getOperation() const;

    Tool *getToolUsed() const;
    void setToolUsed(Tool *value);

    int getUseDuration() const;
    void setUseDuration(int value);

private:

    const int toolUsageID;
    const Operation *operation;
    Tool *toolUsed;
    int useDuration; // (hours)

signals:

public slots:

};

#endif // TOOLUSAGE_H
