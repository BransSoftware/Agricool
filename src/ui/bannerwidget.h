#ifndef BANNERWIDGET_H
#define BANNERWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


class BannerWidget : public QFrame
{
    Q_OBJECT
public:
     BannerWidget(QWidget *parent = 0);
     ~BannerWidget();

private :
    QLabel* plotName;
    QLabel* plotSize;
    QLabel* currentCycle;
    QPushButton* edit;
    QPushButton* expand;
    QGridLayout* lay;

    QLabel* details1;
    QLabel* details2;
    QLabel* details3;


signals:

public slots:

    void showHideDetails();



};

#endif // BANNERWIDGET_H
