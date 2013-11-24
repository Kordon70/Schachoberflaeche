#include "zug.h"


Zug::Zug(SchachLogik* logik) {
	this->logik = logik;
}

void Zug::beginneZug(Position* startposition) {
	this->startPosition = startPosition;
}

void Zug::beendeZug(Position* zielPosition) {
	logik->ziehen(startPosition, zielPosition);
}

Zug::~Zug(void)
{
}
