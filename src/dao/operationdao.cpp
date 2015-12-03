#include "operationdao.h"

OperationDao::OperationDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Operation>(parent, db)
{
    setTable("Operation");
}

Operation* OperationDao::createFromDb(QSqlRecord record)
{
    CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    
    QDateTime date;
    date.setTime_t(record.value(3).toUInt());
    
    return new Operation(record.value(0).toInt(), //id
        cultureCycle, // culture cycle
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
    fields["name"] = model->getOperationName();
    fields["operationDate"] = QString::number(model->getOperationDate().toTime_t());
    fields["duration"] = QString::number(model->getDuration());
    fields["employeeWorkHourCost"] = QString::number(model->getEmployeeWorkHourCost());
    fields["operationType"] = QString::number(static_cast<int>(model->getOperationType()));
    fields["openComment"] = model->getComment();

    return "operationID";
}
