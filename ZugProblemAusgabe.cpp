#include "ZugProblemAusgabe.h"


ZugProblemAusgabe::ZugProblemAusgabe(ZugProblem zugProblem) : QObject(0) {
	fehlerAusgabe = new QDialog;
	fehlerAusgabe->setWindowModality(Qt::ApplicationModal);
	fehlerAusgabe->setWindowFlags(fehlerAusgabe->windowFlags() & ~Qt::WindowContextHelpButtonHint & 
		~Qt::WindowCloseButtonHint);
	fehlerAusgabe->setWindowTitle("Zug ungültig");

	QLabel* fehlertext = getFehlertext(zugProblem);
	QPushButton* ok = new QPushButton("OK");
	ok->setFixedWidth(100);
	QWidget::connect(ok, SIGNAL(clicked()), this, SLOT(ok()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(fehlertext);
	layout->addWidget(ok, 0, Qt::AlignCenter);
	

	fehlerAusgabe->setLayout(layout);
	fehlerAusgabe->show();
}

QLabel* ZugProblemAusgabe::getFehlertext(ZugProblem zugProblem) {
	switch (zugProblem)	{
	case STARTFELD_IST_LEER:
		return new QLabel("Es steht keine Figur auf dem Startfeld, die bewegt werden kann.");
	case ZUG_NICHT_REGELKONFORM:
		return new QLabel("Der Zug ist nicht Regelkonform.");
	case START_ODER_ZIELPOSITION_UNGUELTIG:
		return new QLabel("Das Start-/Zielfeld ist keine gültige Position.");
	case SPIEL_NOCH_NICHT_GESTARTET:
		return new QLabel("Das Spiel ist noch nicht gestartet.");
	case FARBE_IST_NICHT_AN_DER_REIHE:
		return new QLabel("Die andere Farbe ist an der Reihe.");
	case SPIEL_BEENDET:
		return new QLabel("Das Spiel ist bereits beendet.");
	case EVENTUELL_ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht möglich, da es eventuell ein Zug ist Schach wäre.");
	case ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht möglich, da es ein Zug ist Schach wäre.");
	case KEIN_PROBLEM_GEFUNDEN:
		return new QLabel("Glückwunsch ein möglicher Zug, abr kein guter :D.\n Außerdem ist die Ausgabe viel zu lang und sieht deshalb ziehmich scheiße aus");
	default:
		break;
	}
}

void ZugProblemAusgabe::ok() {
	fehlerAusgabe->close();
}

ZugProblemAusgabe::~ZugProblemAusgabe() {
}
