#ifndef TOOLDAO_H
#define TOOLDAO_H

#include "src/dao/plotdao.h"

class ToolDao : public DaoBase<Tool>
{
public:
    ToolDao(DbService * parent, QSqlDatabase db);
    Tool* fillFromDb(QSqlRecord record);
};

#endif // TOOLDAO_H
