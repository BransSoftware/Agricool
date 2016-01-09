#include "src/ui/plotbanner.h"
#include "src/dao/plotdao.h"
#include "src/ui/plotwidget.h"
#include <QDebug>

PlotBanner::PlotBanner(DbService *d, Plot* p, QWidget *parent) :
    QFrame(parent)
{
    db = d;
    plot=p;
    isEditable = false;
    this->setMinimumSize(400,40);
//    this->setStyleSheet("background-color: lightblue;"
//                        "border-radius: 10px;");


    plotNameL = new QLabel(tr("Nom : "), this);
    plotSizeL = new QLabel(tr("Superficie : "), this);
    //retrieve active cycles
    QString cycleStr = QString(tr("En cours : "));

    foreach(CultureCycle* c, plot->getCultureCycles())
    {
        if(!c->getIsComplete())
            cycleStr.append(c->getCycleName()).append(tr(", "));
    }

    if(cycleStr.endsWith(", "))
        cycleStr.chop(2);

    currentCycleL = new QLabel(cycleStr, this);
    editB = new QPushButton(QIcon(":/resources/icons/edit.png"), tr(""), this);
    editB->setToolTip(tr("Modifier la parcelle"));
    expandB = new QPushButton(QIcon(":/resources/icons/expand.png"), tr(""), this);
    expandB->setToolTip(tr("Montrer les détails"));

    isOwnerL = new QLabel(tr("Je suis propriétaire : "), this);
    rentL = new QLabel(tr("Loyer annuel : "), this);
    commentL = new QLabel(tr("Description : "), this);

    plotNameLE = new QLineEdit(plot->getPlotName(), this);
    plotSizeSB = new QDoubleSpinBox(this);
    plotSizeSB->setRange(0,999.999);
    plotSizeSB->setDecimals(3);
    plotSizeSB->setSuffix(tr(" Ha"));
    plotSizeSB->setValue(plot->getSize()/10000);

    isOwnerCB = new QComboBox(this);
    isOwnerCB->addItem(tr("non"));
    isOwnerCB->addItem(tr("oui"));
    isOwnerCB->setCurrentIndex((int)plot->getIsOwned());

    rentSB = new QDoubleSpinBox(this);
    rentSB->setRange(0,999999999.99);
    rentSB->setDecimals(2);
    rentSB->setSuffix(tr(" €"));
    rentSB->setValue(plot->getYearlyRent());

    commentLE = new QLineEdit(plot->getComment(), this);

    cycleCountL = new QLabel(QString(tr("Nombre de Cycles : ")).append(QString::number(plot->getCultureCycles().size())), this);

//    soilQualityL = new QLabel(tr("Qualité du sol : "), this);
//    waterDrainageL = new QLabel(tr("Qualité du drainage : "), this);
//    rocksQuantityL = new QLabel(tr("Pierres au sol : "), this);
//    animalDamageRisksL = new QLabel(tr("Dégâts causés par la faune : "), this);
//    climateDamageRisksL = new QLabel(tr("Dégâts causés par les intempéries : "), this);
//    QComboBox* soilQualityCB;
//    QComboBox* waterDrainageCB;
//    QComboBox* rocksQuantityCB;
//    QComboBox* animalDamageRisksCB;
//    QComboBox* climateDamageRisksCB;

    acceptB = new QPushButton(QIcon(":/resources/icons/ok.png"), tr(""), this);
    acceptB->setToolTip(tr("Sauvegarder les modifications"));

    cancelB = new QPushButton(QIcon(":/resources/icons/cancel.png"), tr(""), this);
    cancelB->setToolTip(tr("Annuler la modification"));

    resetB = new QPushButton(QIcon(":/resources/icons/reset.png"), tr(""), this);
    resetB->setToolTip(tr("Revenir aux valeurs d'origine"));

    deleteB = new QPushButton(QIcon(":/resources/icons/delete.png"), tr(""), this);
    deleteB->setToolTip(tr("Supprimer la parcelle "));

    connect(acceptB, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelB, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(resetB, SIGNAL(clicked()), this, SLOT(resetDefaults()));

    isOwnerL->setVisible(false);
    isOwnerCB->setVisible(false);
    rentL->setVisible(false);
    rentSB->setVisible(false);
    commentL->setVisible(false);
    commentLE->setVisible(false);
    cycleCountL->setVisible(false);
    acceptB->setVisible(false);
    cancelB->setVisible(false);
    resetB->setVisible(false);

    //build layout
    lay = new QGridLayout(this);
    lay->addWidget(plotNameL, 0,0);
    lay->addWidget(plotNameLE,0,1);
    lay->addWidget(plotSizeL, 0,2);
    lay->addWidget(plotSizeSB,0,3);
    lay->addWidget(currentCycleL, 0,4,Qt::AlignCenter);
    lay->addWidget(editB, 0,5);
    lay->addWidget(acceptB, 0,5);
    lay->addWidget(resetB, 0,6);
    lay->addWidget(cancelB, 0,7);
    lay->addWidget(expandB, 0,8);
    lay->addWidget(deleteB, 0,9);
    lay->addWidget(isOwnerL, 1,0);
    lay->addWidget(isOwnerCB,1,1,1,1, Qt::AlignLeft);
    lay->addWidget(rentL, 1,2);
    lay->addWidget(rentSB,1,3,1,1, Qt::AlignLeft);
    lay->addWidget(cycleCountL, 2,0,1,2);
    lay->addWidget(commentL, 3,0,1,1);
    lay->addWidget(commentLE, 3,1,1,5, Qt::AlignLeft);


    //    lay->addWidget(soilQualityL, 3,1,1,6);
    //    lay->addWidget(waterDrainageL, 4,1,1,6);
    //    lay->addWidget(rocksQuantityL, 5,1,1,6);
    //    lay->addWidget(animalDamageRisksL, 6,1,1,6);
    //    lay->addWidget(climateDamageRisksL, 7,1,1,6);
    for(int i =0; i<9; i++)
        lay->setColumnMinimumWidth(i,10);

    lay->setColumnStretch(4,10);
    this->setLayout(lay);


//    soilQualityL->setVisible(false);
//    waterDrainageL->setVisible(false);
//    rocksQuantityL->setVisible(false);
//    animalDamageRisksL->setVisible(false);
//    climateDamageRisksL->setVisible(false);


    connect(expandB, SIGNAL(clicked()),this, SLOT(showDetails()));
    connect(editB, SIGNAL(clicked()), this, SLOT(editPlot()));
    connect(deleteB, SIGNAL(clicked()), this, SLOT(deletePlot()));

    connect(this, SIGNAL(editableChanged(bool)), plotNameLE, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(editableChanged(bool)), plotSizeSB, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(editableChanged(bool)), isOwnerCB, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(editableChanged(bool)), rentSB, SLOT(setEnabled(bool)));
    connect(this, SIGNAL(editableChanged(bool)), commentLE, SLOT(setEnabled(bool)));

    this->setPlot(p);

    emit editableChanged(isEditable);

}

Plot* PlotBanner::getPlot()
{
    return plot;
}

void PlotBanner::showDetails()
{

    isOwnerL->setVisible(true);
    isOwnerCB->setVisible(true);
    rentL->setVisible(true);
    rentSB->setVisible(true);
    commentL->setVisible(true);
    commentLE->setVisible(true);
    cycleCountL->setVisible(true);
//  acceptB->setVisible(false);
//  cancelB->setVisible(false);
//  resetB->setVisible(false);
//  soilQualityL->setVisible(true);
//  waterDrainageL->setVisible(true);
//  rocksQuantityL->setVisible(true);
//  animalDamageRisksL->setVisible(true);
//  climateDamageRisksL->setVisible(true);
    expandB->setToolTip(tr("Hide Details"));
    expandB->setIcon(QIcon(":/resources/icons/shrink.png"));
    disconnect(expandB,0,0,0);
    connect(expandB, SIGNAL(clicked()), this, SLOT(hideDetails()));


}

void PlotBanner::hideDetails()
{

    isOwnerL->setVisible(false);
    isOwnerCB->setVisible(false);
    rentL->setVisible(false);
    rentSB->setVisible(false);
    commentL->setVisible(false);
    commentLE->setVisible(false);
    cycleCountL->setVisible(false);
//  acceptB->setVisible(false);
//  cancelB->setVisible(false);
//  resetB->setVisible(false);
//  soilQualityL->setVisible(false);
//  waterDrainageL->setVisible(false);
//  rocksQuantityL->setVisible(false);
//  animalDamageRisksL->setVisible(false);
//  climateDamageRisksL->setVisible(false);
    expandB->setToolTip(tr("Show Details"));
    expandB->setIcon(QIcon(":/resources/icons/expand.png"));
    disconnect(expandB,0,0,0);
    connect(expandB, SIGNAL(clicked()), this, SLOT(showDetails()));

}

void PlotBanner::setPlot(Plot *value)
{
    this->plot = value;

    defName = plot->getPlotName();
    defSize = plot->getSize();
    defIsOwner = plot->getIsOwned();
    defRent = plot->getYearlyRent();
    defComment = plot->getComment();
    defSoilQuality = plot->getSoilQuality();
    defWaterDrainage = plot->getWaterDrainage();
    defRocksQuantity = plot->getRocksQuantity();
    defAnimalDamageRisks = plot->getAnimalDamageRisks();
    defClimateDamageRisks = plot->getClimateDamageRisks();

    resetDefaults();
}

void PlotBanner::editPlot(){

    //test only
    editB->setVisible(false);
    acceptB->setVisible(true);
    cancelB->setVisible(true);
    resetB->setVisible(true);
    emit editableChanged(true);
    showDetails();

}

void PlotBanner::accept()
{
    if(plotNameLE->text().trimmed().isEmpty())
        QMessageBox::warning(this, tr("Nom de parcelle invalide"), tr("Vous devez entrer un nom de parcelle pour valider les modifications"));
    else
    {
        QLocale french(QLocale::French);

        plot->setPlotName(plotNameLE->text());
        plot->setSize(french.toDouble(plotSizeSB->text().split(' ').first())*10000.0);
        plot->setIsOwned((bool)isOwnerCB->currentIndex());
        plot->setYearlyRent(french.toDouble(rentSB->text().split(' ').first()));
        plot->setComment(commentLE->text());

        isEditable=false;
        setPlot(plot);
        emit editableChanged(isEditable);

        acceptB->setVisible(false);
        cancelB->setVisible(false);
        resetB->setVisible(false);
        editB->setVisible(true);

//        plot->setSoilQuality();
//        plot->setWaterDrainage();
//        plot->setRocksQuantity();
//        plot->setAnimalDamageRisks();
//        plot->setClimateDamageRisks();

        db->getDao<PlotDao>()->update(plot);
    }
}

void PlotBanner::resetDefaults()
{
    plotNameLE->setText(defName);
    plotSizeSB->setValue(defSize/10000);
    isOwnerCB->setCurrentIndex((int)defIsOwner);
    rentSB->setValue(defRent);
    commentLE->setText(defComment);


//    soilQualityCB->setCurrentText(subjectiveQualityToString(defSoilQuality));
//    waterDrainageCB->setCurrentText(subjectiveQualityToString(defWaterDrainage));
//    rocksQuantityCB->setCurrentText(SubjectiveFrequencyToString(defRocksQuantity));
//    animalDamageRisksCB->setCurrentText(SubjectiveFrequencyToString(defAnimalDamageRisks));
//    climateDamageRisksCB->setCurrentText(SubjectiveFrequencyToString(defClimateDamageRisks));

}

void PlotBanner::cancel()
{
    isEditable=false;
    resetDefaults();
    acceptB->setVisible(false);
    cancelB->setVisible(false);
    resetB->setVisible(false);
    editB->setVisible(true);
    emit editableChanged(isEditable);

}

void PlotBanner::deletePlot()
{
    if (QMessageBox::warning(this,tr("Confirmer la suppression"),\
                             tr("Etes-vous sûr de vouloir supprimer la parcelle ").append(plot->getPlotName())\
                             .append(tr(" ?")),QMessageBox::Ok, QMessageBox::Cancel)==QMessageBox::Ok)
    {
        db->getDao<PlotDao>()->remove(plot->getPlotID());
        //((PlotWidget*)this->parent())->update();
        qDebug() << "remove plot:" << plot->getPlotName();
    }
}


PlotBanner::~PlotBanner()
{
}
