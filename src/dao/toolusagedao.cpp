#include "toolusagedao.h"

ToolUsageDao::ToolUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ToolUsage>(parent, db)
{
    setTable("ToolUsage");
}

ToolUsage* ToolUsageDao::createFromDb(QSqlRecord record)
{
    Operation* operation = dbService->getDao<OperationDao>()->get(record.value(1).toInt());
    Tool* tool = dbService->getDao<ToolDao>()->get(record.value(2).toInt());
    
    return new ToolUsage(record.value(0).toInt(), // id
        operation, // operation
        tool, // tool
        record.value(3).toInt() // duration
    );
}

QString ToolUsageDao::exportToDb(ToolUsage* model, QHash<QString, QString> &fields)
{
    fields["toolUsageID"] = QString::number(model->getToolUsageID());
    fields["operationID"] = QString::number(model->getOperation()->getOperationID());
    fields["toolID"] = QString::number(model->getToolUsed()->getToolID());
    fields["toolUsageDuration"] = QString::number(model->getUseDuration());
    //fields["toolUsageDate"] = model->get();

    return "toolUsageID";
}
