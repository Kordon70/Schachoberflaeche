#include "ZugProblemAusgabe.h"


ZugProblemAusgabe::ZugProblemAusgabe(ZugProblem zugProblem) : QObject(0) {
	fehlerAusgabe = new QDialog;
	fehlerAusgabe->setWindowModality(Qt::ApplicationModal);
	fehlerAusgabe->setWindowFlags(fehlerAusgabe->windowFlags() & ~Qt::WindowContextHelpButtonHint & 
		~Qt::WindowCloseButtonHint);
	fehlerAusgabe->setWindowTitle("Zug ung�ltig");
	fehlerAusgabe->setFixedSize(200,120);

	QLabel* fehlertext = getFehlertext(zugProblem);
	QPushButton* ok = new QPushButton("OK");
	ok->setFixedWidth(100);
	QWidget::connect(ok, SIGNAL(clicked()), this, SLOT(ok()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(fehlertext,0 ,Qt::AlignCenter);
	layout->addWidget(ok, 0, Qt::AlignCenter);
	

	fehlerAusgabe->setLayout(layout);
	fehlerAusgabe->show();
}

QLabel* ZugProblemAusgabe::getFehlertext(ZugProblem zugProblem) {
	switch (zugProblem)	{
	case STARTFELD_IST_LEER:
		return new QLabel("Es steht keine Figur auf dem \nStartfeld, die bewegt werden kann.");
	case ZUG_NICHT_REGELKONFORM:
		return new QLabel("Der Zug ist nicht Regelkonform.");
	case START_ODER_ZIELPOSITION_UNGUELTIG:
		return new QLabel("Das Start-/Zielfeld ist keine \ng�ltige Position.");
	case SPIEL_NOCH_NICHT_GESTARTET:
		return new QLabel("Das Spiel ist noch nicht gestartet.");
	case FARBE_IST_NICHT_AN_DER_REIHE:
		return new QLabel("Die andere Farbe ist an der Reihe.");
	case SPIEL_BEENDET:
		return new QLabel("Das Spiel ist bereits beendet.");
	case EVENTUELL_ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht m�glich, da es \neventuell ein Zug ist Schach w�re.");
	case ZUG_INS_SCHACH:
		return new QLabel("Der Zug ist nicht m�glich, \nda es ein Zug ins Schach w�re.");
	}
}

void ZugProblemAusgabe::ok() {
	fehlerAusgabe->close();
}

ZugProblemAusgabe::~ZugProblemAusgabe() {
}
