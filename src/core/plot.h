#ifndef PLOT_H
#define PLOT_H

#include <QObject>
#include <QDateTime>
#include <QList>
#include <QString>
#include "src/core/enums.h"
#include "src/core/culturecycle.h"

class CultureCycle;

class Plot : public QObject
{
    Q_OBJECT
public:

    Plot(int id, QString name = QString(tr("Unknown plot")), double s = 0, bool ow = false, int rent = 0, QString com = QString(tr("")), \
         SubjectiveQuality sq = SubjectiveQuality::Undef, SubjectiveQuality wd = SubjectiveQuality::Undef, SubjectiveFrequency rq = SubjectiveFrequency::Undef, \
          SubjectiveFrequency ar = SubjectiveFrequency::Undef, SubjectiveFrequency cr = SubjectiveFrequency::Undef, QObject *parent = 0);
    ~Plot();

    int getPlotID() const;

    QString getPlotName() const;
    void setPlotName(const QString &value);

    double getSize() const;
    void setSize(double value);

    bool getIsOwned() const;
    void setIsOwned(bool value);

    int getYearlyRent() const;
    void setYearlyRent(int value);

    QList<CultureCycle *> getCultureCycles() const;
    void setCultureCycles(const QList<CultureCycle *> &value);

    QString getComment() const;
    void setComment(const QString &value);

    SubjectiveQuality getSoilQuality() const;
    void setSoilQuality(const SubjectiveQuality &value);

    SubjectiveQuality getWaterDrainage() const;
    void setWaterDrainage(const SubjectiveQuality &value);

    SubjectiveFrequency getRocksQuantity() const;
    void setRocksQuantity(const SubjectiveFrequency &value);

    SubjectiveFrequency getAnimalDamageRisks() const;
    void setAnimalDamageRisks(const SubjectiveFrequency &value);

    SubjectiveFrequency getClimateDamageRisks() const;
    void setClimateDamageRisks(const SubjectiveFrequency &value);

private:

    const int plotID;
    QString plotName;
    double size; //plot size in square meter
    bool isOwned; //
    int yearlyRent; // (€)
    QList<CultureCycle *> cultureCycles;
    QString comment;
    SubjectiveQuality soilQuality; //optional
    SubjectiveQuality waterDrainage; //optional
    SubjectiveFrequency rocksQuantity; //optional
    SubjectiveFrequency animalDamageRisks; //optional
    SubjectiveFrequency climateDamageRisks; //optional

signals:

public slots:



};

#endif // PLOT_H
