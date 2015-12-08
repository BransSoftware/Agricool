#ifndef TOOLUSAGEDAO_H
#define TOOLUSAGEDAO_H

#include "src/dao/plotdao.h"

class ToolUsageDao : public DaoBase<ToolUsage>
{
public:
    ToolUsageDao(DbService * parent, QSqlDatabase db);
    QList<ToolUsage*> getToolUsageByOperation(Operation* operation);

protected:
    ToolUsage* createFromDb(QSqlRecord record);
    QString exportToDb(ToolUsage* model, QHash<QString, QString> &fields);
    void postGet(ToolUsage* model);
    void postAdd(ToolUsage* model);
    void postUpdate(ToolUsage* model);
    void postDelete(ToolUsage* model);

private:
    ToolUsage* createFromDb(QSqlRecord record, Operation* operation);
};

#endif // TOOLUSAGEDAO_H
