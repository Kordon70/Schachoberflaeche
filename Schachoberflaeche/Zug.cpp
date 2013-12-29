#include "zug.h"


Zug::Zug(SchachLogik* logik) {
	this->logik = logik;
	spielerAmZug = false; //ToDo auf false setzten
	startPosition = new Position(-1,-1);
}

void Zug::zugBeginnen() {
	spielerAmZug = true;
}

void Zug::beginneZug(Position* startPosition) {
	if(spielerAmZug && !this->startPosition->istPositionGueltig()) {
		this->startPosition = startPosition;
	}
}

void Zug::beendeZug(Position* zielPosition) {
	if(spielerAmZug && startPosition->istPositionGueltig()) {
		logik->ziehen(startPosition, zielPosition);
		oberflaeche->oberflaecheAktualisieren();
		startPosition = new Position(-1,-1);
		spielerAmZug = false;
		logik->zugAbschliessen();
	}
}

void Zug::setzteOberflaeche(OberflaecheInterface* oberflaeche) {
	this->oberflaeche=oberflaeche;
}

Zug::~Zug(void)
{
}
