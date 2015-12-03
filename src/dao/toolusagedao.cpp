#include "toolusagedao.h"

ToolUsageDao::ToolUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ToolUsage>(parent, db)
{
    setTable("ToolUsage");
}

ToolUsage* ToolUsageDao::fillFromDb(QSqlRecord record)
{
    /*Operation* operation = dbService->getDao<OperationDao>()->get(record.value(1).toInt());
    Tool* tool = dbService->getDao<ToolDao>()->get(record.value(2).toInt());
    
    return new ToolUsage(record.value(0).toInt(), // id
        operation, // operation
        tool, // tool
        record.value(3).toInt() // duration
    );*/
    return NULL;
}
