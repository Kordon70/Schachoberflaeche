#include "FigurenWechsel.h"


FigurenWechsel::FigurenWechsel(Figuren& figur)
{
	bauernTausch = new QWidget;
	bauernTausch->setWindowModality(Qt::ApplicationModal);
    bauernTausch->setWindowTitle(QObject::tr("Neues Spiel"));

    QVBoxLayout* layout = new QVBoxLayout;

	//ToDo Methodenaufrufe für Buttons noch falsch

    QPushButton* bauer = new QPushButton("Bauer");
	QWidget::connect(bauer,SIGNAL(clicked()), this, SLOT(setDame(figur)));
	QPushButton* turm = new QPushButton("Turm");
	QWidget::connect(turm,SIGNAL(clicked()), this, SLOT(setDame(figur)));
	QPushButton* laufer = new QPushButton("Läufer");
	QWidget::connect(laufer,SIGNAL(clicked()), this, SLOT(setDame(figur)));
	QPushButton* springer = new QPushButton("Springer");
	QWidget::connect(springer,SIGNAL(clicked()), this, SLOT(setDame(figur)));
	QPushButton* dame = new QPushButton("Dame");
	QWidget::connect(dame,SIGNAL(clicked()), this, SLOT(setDame(figur)));
	
    layout->addWidget(bauer);
	layout->addWidget(turm);
	layout->addWidget(laufer);
	layout->addWidget(springer);
	layout->addWidget(dame);
    

    bauernTausch->setLayout(layout);
    bauernTausch->show();
}

void FigurenWechsel::setDame(Figuren& figur) {
	figur = DAME;

}


FigurenWechsel::~FigurenWechsel(void)
{
}
