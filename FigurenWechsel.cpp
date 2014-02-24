#include "FigurenWechsel.h"


FigurenWechsel::FigurenWechsel(FigurTyp& figur) : QObject(0), wechselFigur(figur) {

	bauernTausch = new QDialog;
	bauernTausch->setWindowModality(Qt::ApplicationModal);
	bauernTausch->setWindowFlags(bauernTausch->windowFlags() & ~Qt::WindowContextHelpButtonHint & 
		~Qt::WindowCloseButtonHint);
	bauernTausch->setWindowTitle("Bauerntausch");

	QLabel* auswahl = new QLabel("Mit welcher Figur wollen Sie ihren Bauer tauschen?");
	QPushButton* turm = new QPushButton("Turm");
	QWidget::connect(turm,SIGNAL(clicked()), this, SLOT(setTurm()));
	QPushButton* laufer = new QPushButton("Läufer");
	QWidget::connect(laufer,SIGNAL(clicked()), this, SLOT(setLauefer()));
	QPushButton* springer = new QPushButton("Springer");
	QWidget::connect(springer,SIGNAL(clicked()), this, SLOT(setSpringer()));
	QPushButton* dame = new QPushButton("Dame");
	QWidget::connect(dame,SIGNAL(clicked()), this, SLOT(setDame()));

    QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(auswahl);
	layout->addWidget(turm);
	layout->addWidget(laufer);
	layout->addWidget(springer);
	layout->addWidget(dame);
    
    bauernTausch->setLayout(layout);
	bauernTausch->exec();
}

void FigurenWechsel::setTurm() {
	wechselFigur = TURM;
	bauernTausch->close();
}

void FigurenWechsel::setLauefer() {
	wechselFigur = LAEUFER;
	bauernTausch->close();
}

void FigurenWechsel::setSpringer() {
	wechselFigur = SPRINGER;
	bauernTausch->close();
}

void FigurenWechsel::setDame() {
	wechselFigur = DAME;
	bauernTausch->close();
}


FigurenWechsel::~FigurenWechsel() {
}
