#include "src/ui/bannerwidget.h"

BannerWidget::BannerWidget(QWidget *parent) :
    QFrame(parent)
{
    this->setStyleSheet("background-color: lightblue;"
                        "border-radius: 10px;");

    this->setMinimumSize(400,40);

    plotName = new QLabel(tr("Brans"), this);
    plotSize = new QLabel(tr("10 Ha"), this);
    currentCycle = new QLabel(tr("Current cycle : Wheat"), this);
    edit = new QPushButton(QIcon(":/resources/icons/edit.png"), tr(""), this);
    edit->setToolTip(tr("Edit"));
    expand = new QPushButton(QIcon(":/resources/icons/expand.png"), tr(""), this);
    expand->setToolTip(tr("Show Details"));

    details1 = new QLabel(tr("blablabla"), this);
    details2 = new QLabel(tr("blablabla"), this);
    details3 = new QLabel(tr("blablabla"), this);

    lay = new QGridLayout(this);
    lay->addWidget(plotName, 0,0,1,2);
    lay->addWidget(plotSize, 0,2,1,1);
    lay->addWidget(currentCycle, 0,3,1,3);
    lay->addWidget(edit, 0,6,1,1);
    lay->addWidget(expand, 0,7,1,1);
    lay->addWidget(details1, 1,1,1,6);
    lay->addWidget(details2, 2,1,1,6);
    lay->addWidget(details3, 3,1,1,6);
    this->setLayout(lay);

    details1->setVisible(false);
    details2->setVisible(false);
    details3->setVisible(false);

    connect(expand, SIGNAL(clicked()),this, SLOT(showHideDetails()));

}

void BannerWidget::showHideDetails(){

    QPropertyAnimation *anim = new QPropertyAnimation(this, "minimumHeight");


    if (!details1->isVisible()){

//            anim->setStartValue(40);
//            anim->setEndValue(160);
//            anim->setDuration(200);
//            anim->start(QAbstractAnimation::DeleteWhenStopped);
            details1->show();
            details2->show();
            details3->show();
            expand->setToolTip(tr("Hide Details"));
            expand->setIcon(QIcon(":/resources/icons/shrink.png"));
        }
        else{

//            anim->setStartValue(160);
//            anim->setEndValue(40);
//            anim->setDuration(200);
//            anim->start(QAbstractAnimation::DeleteWhenStopped);
            details1->hide();
            details2->hide();
            details3->hide();
            expand->setToolTip(tr("Show Details"));
            expand->setIcon(QIcon(":/resources/icons/expand.png"));
        }

}

BannerWidget::~BannerWidget()
{
}
