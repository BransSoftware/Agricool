#ifndef TOOL_H
#define TOOL_H

#include <QObject>
#include <QString>
#include "enums.h"

class Tool : public QObject
{
    Q_OBJECT
public:

    Tool(int id, QString name, int cph = 0, ToolType t = ToolType::Undef, QObject *parent = 0);
    ~Tool();

    int getToolID() const;

    QString getToolName() const;
    void setToolName(const QString &value);

    int getCostPerHour() const;
    void setCostPerHour(int value);

    ToolType getType() const;
    void setType(const ToolType &value);

private:


    const int toolID;
    QString toolName;
    int costPerHour; //(€)
    ToolType type; // [optional]

signals:

public slots:

};

#endif // TOOL_H
