#include "zug.h"


Zug::Zug(SchachLogik* logik) {
	this->logik = logik;
	spielerAmZug = true; //ToDo auf false setzten
	myfile.open ("example.txt"); //löschen
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
		myfile << "Zugvon " << startPosition << "nach" << zielPosition;  //löschen
		logik->ziehen(startPosition, zielPosition);
		startPosition = 0;
		spielerAmZug = false;
	}
}

Zug::~Zug(void)
{
	 myfile.close(); //löschen
}
