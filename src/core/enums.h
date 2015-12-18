#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>
#include <QString>

 enum class QuantityUnit : int { Undef = 0, kg, quintal, ton, L, hL, m3 }; //todo : complete list
 enum class OperationType : int { Undef = 0, SoilTreatment, Sowing, PlantTreatment, Harvest }; //todo : complete list
 enum class SubjectiveQuality : int { Undef = 0, bad, average, good };
 enum class SubjectiveFrequency : int { Undef = 0, none, some, lots };
 enum class ProductType : int { Undef = 0, Seed, Other }; //todo : complete list
 enum class ToolType : int { Undef = 0, Tractor, Other }; //todo : complete list

static QString quantityUnitToString(QuantityUnit qu)
{
    switch(qu)
    {
        case QuantityUnit::Undef:
            return QObject::tr(" Non défini");
        case QuantityUnit::kg:
            return QObject::tr(" kg");
        case QuantityUnit::quintal:
            return QObject::tr(" quintaux");
        case QuantityUnit::ton:
            return QObject::tr(" tonnes");
        case QuantityUnit::L:
            return QObject::tr(" L");
        case QuantityUnit::hL:
            return QObject::tr(" hL");
        case QuantityUnit::m3:
            return QObject::tr(" m³");
        default :
            return QObject::tr(" Erreur");
    }

}

static QString subjectiveQualityToString(SubjectiveQuality sq)
{
    switch(sq)
    {
        case SubjectiveQuality::Undef:
            return QObject::tr("Non défini");
        case SubjectiveQuality::bad:
            return QObject::tr("mauvaise");
        case SubjectiveQuality::average:
            return QObject::tr("moyenne");
        case SubjectiveQuality::good:
            return QObject::tr("bonne");
        default :
            return QObject::tr("Erreur");
    }

}

#endif // ENUMS_H
