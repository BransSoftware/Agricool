#include "toolusage.h"

ToolUsage::ToolUsage(int id, Operation *op, Tool *tool, int duration) :
    QObject(op), toolUsageID(id), toolUsed(tool), useDuration(duration)
{

}

int ToolUsage::getToolUsageID() const
{
    return toolUsageID;
}
const Operation *ToolUsage::getOperation() const
{
    return operation;
}

Tool *ToolUsage::getToolUsed() const
{
    return toolUsed;
}

void ToolUsage::setToolUsed(Tool *value)
{
    toolUsed = value;
}
int ToolUsage::getUseDuration() const
{
    return useDuration;
}

void ToolUsage::setUseDuration(int value)
{
    useDuration = value;
}

ToolUsage::~ToolUsage()
{

}


