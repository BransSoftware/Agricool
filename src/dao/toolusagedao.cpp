#include "toolusagedao.h"

ToolUsageDao::ToolUsageDao(DbService * parent, QSqlDatabase db)
    : DaoBase<ToolUsage>(parent, db)
{
    setTable("ToolUsage");
}

ToolUsage* ToolUsageDao::fillFromDb(QSqlRecord record)
{
    //return new ToolUsage(record.value(1));
    return NULL;
}
