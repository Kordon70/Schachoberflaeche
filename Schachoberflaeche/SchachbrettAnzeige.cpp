#include "SchachbrettAnzeige.h"

SchachbrettAnzeige::SchachbrettAnzeige(SchachLogik* logik, Zug* schachZug) {
	this->logik= logik;
	this->schachZug = schachZug;
	schachFelder = vector<Schachfeld*>();		
}

QVBoxLayout* SchachbrettAnzeige::initializeChessField() {
	QVBoxLayout* verticalLayout = new QVBoxLayout;
    for (unsigned int zeile = 0; zeile < 8; zeile++) {
		QHBoxLayout* horizontalLayout = new QHBoxLayout();
		for(unsigned int spalte = 0; spalte < 8; spalte++) {
			feld = erzeugeFeld(new Position(zeile, spalte));
			schachFelder.push_back(feld);
			horizontalLayout->addWidget(feld);
		}
		verticalLayout->addLayout(horizontalLayout);
    }
    return verticalLayout;
}

Schachfeld* SchachbrettAnzeige::erzeugeFeld(Position* position) {
	return new Schachfeld(logik, schachZug, position);
}

void SchachbrettAnzeige::aktualisiereSchachfeld() {
	for (Schachfeld* feld: schachFelder) {
		feld->aendereBild();
	}
}

void SchachbrettAnzeige::zugZurueck() {
	if(!logik->istSpielBeendet()) {
		logik->zugRueckgaengig(logik->welcheFarbeIstDran());
		schachZug->aktuallisiereOberflaeche();
	}
}

SchachbrettAnzeige::~SchachbrettAnzeige() {
	for (Schachfeld* feld: schachFelder) {
		delete feld;
	}
}
