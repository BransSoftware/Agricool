#include "tooldao.h"

ToolDao::ToolDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Tool>(parent, db)
{
    setTable("Tool");
}

Tool* ToolDao::fillFromDb(QSqlRecord record)
{
    /*return new Tool(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        record.value(2).toInt(), // cost per hour
        static_cast<ToolType>(record.value(3).toInt()),
        this
    );*/
    return NULL;
}
