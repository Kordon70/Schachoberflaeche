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

void SchachbrettAnzeige::startNewGame() {

}

/*void SchachbrettAnzeige::setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett) {
	for(unsigned row = 0; row < 8; row++) {
		for(unsigned column = 0; column < 8; column++) {
			//chessFiedVector[row]->at(column)->changePicture(&logikSchachbrett->getFigurAnPosition(Position(column, row)));
		}
	}
}
*/