#ifndef TOOLDAO_H
#define TOOLDAO_H

#include "src/dao/plotdao.h"

class ToolDao : public DaoBase<Tool>
{
public:
    ToolDao(DbService * parent, QSqlDatabase db);
protected:
    Tool* createFromDb(QSqlRecord record);
    QString exportToDb(Tool* model, QHash<QString, QString> &fields);
    void postGet(Tool* model);
    void postAdd(Tool* model);
    void postUpdate(Tool* model);
    void postDelete(Tool* model);
};

#endif // TOOLDAO_H
