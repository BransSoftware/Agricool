#include "operationdao.h"

OperationDao::OperationDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Operation>(parent, db)
{
    setTable("Operation");
}

Operation* OperationDao::createFromDb(QSqlRecord record)
{
    return createFromDb(record);
}

Operation* OperationDao::createFromDb(QSqlRecord record, CultureCycle* cycle)
{
    if (cycle == NULL)
    {
        cycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    }

    QDateTime date;
    date.setTime_t(record.value(3).toUInt());
    
    return new Operation(record.value(0).toInt(), //id
        cycle, // culture cycle
        record.value(2).toString(), // name
        date, // date
        record.value(4).toInt(), // duration
        record.value(5).toInt(), // employee work hour
        static_cast<OperationType>(record.value(6).toInt()), // quantity unit
        record.value(7).toString() // comment
    );
}

QString OperationDao::exportToDb(Operation* model, QHash<QString, QString> &fields)
{
    fields["operationID"] = QString::number(model->getOperationID());
    fields["cycleID"] = QString::number(model->getCycle()->getCycleID());
    if (!model->getOperationName().isEmpty())
    {
        fields["name"] = "'" + model->getOperationName() + "'";
    }
    fields["operationDate"] = QString::number(model->getOperationDate().toTime_t());
    fields["duration"] = QString::number(model->getDuration());
    fields["employeeWorkHourCost"] = QString::number(model->getEmployeeWorkHourCost());
    fields["operationType"] = QString::number(static_cast<int>(model->getOperationType()));
    if (!model->getComment().isEmpty())
    {
        fields["openComment"] = "'" + model->getComment() + "'";
    }

    return "operationID";
}

QList<Operation*> OperationDao::getByCultureCycle(CultureCycle* cycle)
{
    QList<Operation*> operations;
    QString req = QString("SELECT * FROM " + tableName() + " WHERE cycleID=:id");
    //qDebug() << "OperationDao::getByCultureCycle: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", cycle->getCycleID());
    if (!q.exec())
    {
        qWarning() << q.lastError();
    }

    while (q.next())
    {
        Operation* operation = createFromDb(q.record(), cycle);
        postGet(operation);
        operations.append(operation);
    }

    return operations;
}

QList<Operation*> OperationDao::getAll()
{
    return getAll(true);
}

QList<Operation*> OperationDao::getAll(bool isRecursive)
{
    QList<Operation*> models = DaoBase::getAll();

    if (isRecursive)
    {
        for(Operation* model : models)
        {
            postGet(model);
        }
    }

    return models;
}

Operation* OperationDao::get(int id)
{
    return get(id, true);
}

Operation* OperationDao::get(int id, bool isRecursive)
{
    Operation* model = DaoBase::get(id);

    if (isRecursive)
    {
        postGet(model);
    }

    return model;
}

void OperationDao::add(Operation* model)
{
    DaoBase::add(model);
    postAdd(model);
}

void OperationDao::update(Operation* model)
{
    DaoBase::update(model);
    postUpdate(model);
}

void OperationDao::remove(int id)
{
    Operation* operation = get(id);

    postRemove(operation);
    DaoBase::remove(operation->getOperationID());
}

void OperationDao::removeAll()
{
    QList<Operation*> operations = getAll();

    for(Operation* operation : operations)
    {
        postRemove(operation);
    }

    DaoBase::removeAll();
}

void OperationDao::postGet(Operation* model)
{
    model->setProductUsed(dbService->getDao<ProductUsageDao>()->getProductUsageByOperation(model));
    model->setToolUsed(dbService->getDao<ToolUsageDao>()->getToolUsageByOperation(model));
}

void OperationDao::postAdd(Operation* model)
{
    for (ProductUsage* productUsed : model->getProductUsed())
    {
        dbService->getDao<ProductUsageDao>()->add(productUsed);
    }
    for (ToolUsage* toolUsed : model->getToolUsed())
    {
        dbService->getDao<ToolUsageDao>()->add(toolUsed);
    }
}

void OperationDao::postUpdate(Operation* model)
{
    for (ProductUsage* productUsed : model->getProductUsed())
    {
        dbService->getDao<ProductUsageDao>()->update(productUsed);
    }
    for (ToolUsage* toolUsed : model->getToolUsed())
    {
        dbService->getDao<ToolUsageDao>()->update(toolUsed);
    }
}

void OperationDao::postRemove(Operation* model)
{
    for (ProductUsage* productUsed : model->getProductUsed())
    {
        dbService->getDao<ProductUsageDao>()->remove(productUsed->getProductUsageID());
    }
    for (ToolUsage* toolUsed : model->getToolUsed())
    {
        dbService->getDao<ToolUsageDao>()->remove(toolUsed->getToolUsageID());
    }
}
