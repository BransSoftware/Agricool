#include "src/dao/plotdao.h"

PlotDao::PlotDao(DbService *parent, QSqlDatabase db)
    : DaoBase<Plot>(parent, db)
{
    setTable("Plot");
}

Plot* PlotDao::createFromDb(QSqlRecord record)
{
    return new Plot(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        record.value(2).toDouble(), // surface
        record.value(3).toBool(), // isOwned
        record.value(4).toInt(), // rent
        record.value(5).toString(), // comment
        static_cast<SubjectiveQuality>(record.value(6).toInt()), // soil quality
        static_cast<SubjectiveQuality>(record.value(7).toInt()), // waterDrainage
        static_cast<SubjectiveFrequency>(record.value(8).toInt()), // rocksQuantity
        static_cast<SubjectiveFrequency>(record.value(9).toInt()), // animalDamageRisks
        static_cast<SubjectiveFrequency>(record.value(10).toInt()), // climateDamageRisks
        this);
}

QString PlotDao::exportToDb(Plot* model, QHash<QString, QString> &fields)
{
    fields["plotID"] = QString::number(model->getPlotID());
    if (!model->getPlotName().isEmpty())
    {
        fields["name"] = "'" + model->getPlotName() + "'";
    }
    fields["size"] = QString::number(model->getSize());
    fields["isOwned"] = QString::number(model->getIsOwned());
    fields["yearlyRent"] = QString::number(model->getYearlyRent());
    if (!model->getComment().isEmpty())
    {
        fields["comment"] ="'" +  model->getComment() + "'";
    }
    fields["soilQuality"] = QString::number(static_cast<int>(model->getSoilQuality()));
    fields["waterDrainage"] = QString::number(static_cast<int>(model->getWaterDrainage()));
    fields["rocksQuantity"] = QString::number(static_cast<int>(model->getRocksQuantity()));
    fields["animalDamageRisks"] = QString::number(static_cast<int>(model->getAnimalDamageRisks()));
    fields["climateDamageRisks"] = QString::number(static_cast<int>(model->getClimateDamageRisks()));

    return "plotID";
}

QList<Plot*> PlotDao::getAll()
{
    return getAll(true);
}

QList<Plot*> PlotDao::getAll(bool isRecursive)
{
    QList<Plot*> models = DaoBase::getAll();

    if (isRecursive)
    {
        for(Plot* plot : models)
        {
            postGet(plot);
        }
    }

    return models;
}

Plot* PlotDao::get(int id)
{
    return get(id, true);
}

Plot* PlotDao::get(int id, bool isRecursive)
{
    Plot* model = DaoBase::get(id);

    if (isRecursive)
    {
        postGet(model);
    }

    return model;
}

void PlotDao::add(Plot* model)
{
    DaoBase::add(model);
    postAdd(model);
}

void PlotDao::update(Plot* model)
{
    DaoBase::update(model);
    postUpdate(model);
}

void PlotDao::remove(int id)
{
    Plot* plot = get(id);

    postRemove(plot);
    DaoBase::remove(plot->getPlotID());
}

void PlotDao::removeAll()
{
    QList<Plot*> plots = getAll();

    for(Plot* plot : plots)
    {
        postRemove(plot);
    }

    DaoBase::removeAll();
}

void PlotDao::postGet(Plot* model)
{
    QList<CultureCycle*> cycles = dbService->getDao<CultureCycleDao>()->getByPlot(model);
    model->setCultureCycles(cycles);
}

void PlotDao::postAdd(Plot* model)
{
    for (CultureCycle* cycle : model->getCultureCycles())
    {
        dbService->getDao<CultureCycleDao>()->add(cycle);
    }
}

void PlotDao::postUpdate(Plot* model)
{
    for (CultureCycle* cycle : model->getCultureCycles())
    {
        dbService->getDao<CultureCycleDao>()->update(cycle);
    }
}

void PlotDao::postRemove(Plot* model)
{
    for (CultureCycle* cycle : model->getCultureCycles())
    {
        dbService->getDao<CultureCycleDao>()->remove(cycle->getCycleID());
    }
}
