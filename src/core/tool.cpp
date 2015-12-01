#include "src/core/tool.h"

Tool::Tool(int id, QString name, int cph, ToolType t, QObject *parent) :
    QObject(parent), toolID(id), toolName(name), costPerHour(cph), type(t)
{

}

int Tool::getToolID() const
{
    return toolID;
}
QString Tool::getToolName() const
{
    return toolName;
}

void Tool::setToolName(const QString &value)
{
    toolName = value;
}
int Tool::getCostPerHour() const
{
    return costPerHour;
}

void Tool::setCostPerHour(int value)
{
    costPerHour = value;
}
ToolType Tool::getType() const
{
    return type;
}

void Tool::setType(const ToolType &value)
{
    type = value;
}

Tool::~Tool()
{

}
