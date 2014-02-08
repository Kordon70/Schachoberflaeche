#include "SpielerMensch.h"


SpielerMensch::SpielerMensch(Zug* schachZug){
	this->schachZug = schachZug;
}

void SpielerMensch::duBistDran(){
	schachZug->zugBeginnen();
}

Figuren SpielerMensch::tauscheBauern(){
	return KOENIG;
}

void SpielerMensch::spielBeendet() {
	//ToDo implementieren
}

SpielerMensch::~SpielerMensch(){
}
