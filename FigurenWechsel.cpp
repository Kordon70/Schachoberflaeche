#include "FigurenWechsel.h"


FigurenWechsel::FigurenWechsel(void)
{
	bauernTausch = new QWidget;
	bauernTausch->setWindowModality(Qt::ApplicationModal);
    bauernTausch->setWindowTitle(QObject::tr("Neues Spiel"));

    QVBoxLayout* layout = new QVBoxLayout;

	//ToDo Methodenaufrufe für Buttons noch falsch

    QPushButton* bauer = new QPushButton("Bauer");
	QWidget::connect(bauer,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
	QPushButton* turm = new QPushButton("Turm");
	QWidget::connect(turm,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
	QPushButton* laufer = new QPushButton("Läufer");
	QWidget::connect(laufer,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
	QPushButton* springer = new QPushButton("Springer");
	QWidget::connect(springer,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
	QPushButton* dame = new QPushButton("Dame");
	QWidget::connect(dame,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
	
    layout->addWidget(bauer);
	layout->addWidget(turm);
	layout->addWidget(laufer);
	layout->addWidget(springer);
	layout->addWidget(dame);
    

    bauernTausch->setLayout(layout);
    bauernTausch->show();
}


FigurenWechsel::~FigurenWechsel(void)
{
}
