#ifndef TOOLUSAGEDAO_H
#define TOOLUSAGEDAO_H

#include "src/dao/plotdao.h"

class ToolUsageDao : public DaoBase<ToolUsage>
{
public:
    ToolUsageDao(QObject * parent, QSqlDatabase db);
    ToolUsage* fillFromDb(QSqlRecord record);
};

#endif // TOOLUSAGEDAO_H
