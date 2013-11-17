#include "chessfield.h"

chessField::chessField() {
        verticalLayout = new QVBoxLayout;
		schachFelder = new vector<Field*>();
		
}

QVBoxLayout* chessField::initializeChessField(SchachBrettAusgabe* logikSchach) {
    for (unsigned int zeile = 0; zeile < 8; zeile++) {
		QHBoxLayout* horizontalLayout = new QHBoxLayout();
		for(unsigned int spalte = 0; spalte < 8; spalte++) {
			feld = erzeugeFeld(new Position(zeile, spalte), logikSchach);
			schachFelder->push_back(feld);
			horizontalLayout->addWidget(feld);
		}
		verticalLayout->addLayout(horizontalLayout);
    }
    return verticalLayout;
}

Field* chessField::erzeugeFeld(Position* position, SchachBrettAusgabe* logikSchach) {
	pair<Figuren,Farbe> feldBeschreibung = logikSchach->getFigurAnPosition(*position);
	Farbe feldFarbe = logikSchach->getFeldFarbe(position->getZeile(), position->getSpalte());
	return new Field(feldFarbe, *position, feldBeschreibung);
}



void chessField::startNewGame() {

}

void chessField::setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett) {
	for(unsigned row = 0; row < 8; row++) {
		for(unsigned column = 0; column < 8; column++) {
			//chessFiedVector[row]->at(column)->changePicture(&logikSchachbrett->getFigurAnPosition(Position(column, row)));
		}
	}
}
