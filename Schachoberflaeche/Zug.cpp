#include "zug.h"


Zug::Zug(SchachLogik* logik) {
	this->logik = logik;
	spielerAmZug = true; //ToDo auf false setzten
}

void Zug::zugBeginnen() {
	spielerAmZug = true;
}

void Zug::beginneZug(Position* startPosition) {
	if(spielerAmZug) {
		this->startPosition = startPosition;
	}
}

void Zug::beendeZug(Position* zielPosition) {
	if(spielerAmZug && startPosition != 0) {
		logik->ziehen(startPosition, zielPosition);
		oberflaeche->oberflaecheAktualisieren();
		startPosition = 0;
		spielerAmZug = false;
	}
}

void Zug::setzteOberflaeche(OberflaecheInterface* oberflaeche) {
	this->oberflaeche=oberflaeche;
}

Zug::~Zug(void)
{
}
