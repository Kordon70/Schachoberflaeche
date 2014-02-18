#include "ZugProblemAusgabe.h"


ZugProblemAusgabe::ZugProblemAusgabe(ZugProblem zugProblem) : QObject(0) {
	fehlerAusgabe = new QDialog;
	fehlerAusgabe->setWindowModality(Qt::ApplicationModal);
	fehlerAusgabe->setWindowFlags(fehlerAusgabe->windowFlags() & ~Qt::WindowContextHelpButtonHint & 
		~Qt::WindowCloseButtonHint);
	fehlerAusgabe->setWindowTitle("Zug ung�ltig");

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
		return new QLabel("Das Start-/Zielfeld ist keine g�ltige Position.");
	case SPIEL_NOCH_NICHT_GESTARTET:
		return new QLabel("Das Spiel ist noch nicht gestartet.");
	case FARBE_IST_NICHT_AN_DER_REIHE:
		return new QLabel("Die andere Farbe ist an der Reihe.");
	case SPIEL_BEENDET:
		return new QLabel("Das Spiel ist bereits beendet.");
	case EVENTUELL_ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht m�glich, da es eventuell ein Zug ist Schach w�re.");
	case ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht m�glich, da es ein Zug ist Schach w�re.");
	case KEIN_PROBLEM_GEFUNDEN:
		return new QLabel("Gl�ckwunsch ein m�glicher Zug, abr kein guter :D.\n Au�erdem ist die Ausgabe viel zu lang und sieht deshalb ziehmich schei�e aus");
	default:
		break;
	}
}

void ZugProblemAusgabe::ok() {
	fehlerAusgabe->close();
}

ZugProblemAusgabe::~ZugProblemAusgabe() {
}
