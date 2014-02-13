#include "SpielerMensch.h"


SpielerMensch::SpielerMensch(Zug* schachZug, Farbe spielFarbe){
	this->schachZug = schachZug;
	this->spielFarbe = spielFarbe;
}

void SpielerMensch::duBistDran(){
	schachZug->zugBeginnen();
}

Figuren SpielerMensch::tauscheBauern(){
	return KOENIG;
}

void SpielerMensch::spielBeendet() {
	new SpielBeendet();
}

Farbe SpielerMensch::getSpielFarbe() {
	return spielFarbe;
}

SpielerMensch::~SpielerMensch(){
}
