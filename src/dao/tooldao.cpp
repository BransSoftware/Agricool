#include "tooldao.h"

ToolDao::ToolDao(QObject * parent, QSqlDatabase db)
    : DaoBase<Tool>(parent, db)
{
    setTable("Tool");
}

Tool* ToolDao::fillFromDb(QSqlRecord record)
{
    //return new Tool(record.value(1));
    return NULL;
}
