#ifndef PlotBanner_H
#define PlotBanner_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>

#include "src/core/plot.h"

class PlotBanner : public QFrame
{
    Q_OBJECT
public:
     PlotBanner(Plot* p, QWidget *parent = 0);
     ~PlotBanner();

     Plot* getPlot();

private :
    QLabel* plotNameL;
    QLabel* plotSizeL;
    QLabel* currentCycleL;
    QLabel* isOwnerL;
    QLabel* rentL;
    QLabel* cycleCountL;
    QLabel* soilQualityL;
    QLabel* waterDrainageL;
    QLabel* rocksQuantityL;
    QLabel* animalDamageRisksL;
    QLabel* climateDamageRisksL;
    QLabel* commentL;

    QLineEdit* plotNameLE;
    QDoubleSpinBox* plotSizeSB;
    QComboBox* isOwnerCB;
    QDoubleSpinBox* rentSB;
    QLineEdit* commentLE;
    QComboBox* soilQualityCB;
    QComboBox* waterDrainageCB;
    QComboBox* rocksQuantityCB;
    QComboBox* animalDamageRisksCB;
    QComboBox* climateDamageRisksCB;

    QString defName;
    double defSize;
    bool defIsOwner;
    double defRent;
    QString defComment;
    SubjectiveQuality defSoilQuality;
    SubjectiveQuality defWaterDrainage;
    SubjectiveFrequency defRocksQuantity;
    SubjectiveFrequency defAnimalDamageRisks;
    SubjectiveFrequency defClimateDamageRisks;

    QPushButton* expandB;
    QPushButton* editB;
    QPushButton* acceptB;
    QPushButton* cancelB;
    QPushButton* resetB;
    QPushButton* deleteB;
    QGridLayout* lay;

    Plot *plot;

    bool isEditable;

public slots:

    void setPlot(Plot*);
    void hideDetails();
    void showDetails();
    void editPlot();
    void accept();
    void resetDefaults();
    void cancel();
    void deletePlot();

signals:

    void editableChanged(bool);

};

#endif // PlotBanner_H
