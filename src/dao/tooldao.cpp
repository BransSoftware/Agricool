#include "tooldao.h"

ToolDao::ToolDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Tool>(parent, db)
{
    setTable("Tool");
}

Tool* ToolDao::createFromDb(QSqlRecord record)
{
    return new Tool(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        record.value(2).toInt(), // cost per hour
        static_cast<ToolType>(record.value(3).toInt()),
        this
    );
}

QString ToolDao::exportToDb(Tool* model, QHash<QString, QString> &fields)
{
    fields["toolID"] = QString::number(model->getToolID());
    if (!model->getToolName().isEmpty())
    {
        fields["toolName"] = "'" + model->getToolName() + "'";
    }
    fields["costPerHour"] = QString::number(model->getCostPerHour());
    fields["toolType"] = QString::number(static_cast<int>(model->getType()));

    return "toolID";
}

void ToolDao::postGet(Tool* model)
{
}

void ToolDao::postAdd(Tool* model)
{
}

void ToolDao::postUpdate(Tool* model)
{
}

void ToolDao::postDelete(Tool* model)
{
}
