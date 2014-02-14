#include "zug.h"


Zug::Zug(SchachLogik* logik) {
	this->logik = logik;
	spielerAmZug = false;
	startPosition = ungueltigePosition = new Position(-1,-1);
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
		spielerAmZug = false;
		logik->ziehen(*startPosition, *zielPosition);
		aktuallisiereOberflaeche();
		startPosition = ungueltigePosition;
	}
}

void Zug::setzteOberflaeche(OberflaecheInterface* oberflaeche) {
	this->oberflaeche=oberflaeche;
}

void Zug::aktuallisiereOberflaeche() {
	oberflaeche->oberflaecheAktualisieren();
}

Zug::~Zug() {
}
