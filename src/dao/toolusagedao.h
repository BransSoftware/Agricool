#ifndef TOOLUSAGEDAO_H
#define TOOLUSAGEDAO_H

#include "src/dao/plotdao.h"

class ToolUsageDao : public DaoBase<ToolUsage>
{
public:
    ToolUsageDao(DbService * parent, QSqlDatabase db);
    ToolUsage* createFromDb(QSqlRecord record);
    QString exportToDb(ToolUsage* model, QHash<QString, QString> &fields);
};

#endif // TOOLUSAGEDAO_H
