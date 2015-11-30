#ifndef ENUMS_H
#define ENUMS_H

 enum class QuantityUnit { Undef, kg, quintal, ton, L, hL, m3 }; //todo : complete list
 enum class OperationType { Undef, SoilTreatment, Sowing, PlantTreatment, Harvest }; //todo : complete list
 enum class SubjectiveQuality { Undef, bad, average, good };
 enum class SubjectiveFrequency { Undef, none, some, lots };
 enum class ProductType { Undef, Seed, Other }; //todo : complete list
 enum class ToolType { Undef, Tractor, Other }; //todo : complete list

#endif // ENUMS_H
