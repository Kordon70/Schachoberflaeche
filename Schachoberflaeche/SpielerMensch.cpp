#include "SpielerMensch.h"


SpielerMensch::SpielerMensch(void){
}

void SpielerMensch::duBistDran(){
	//SchachbrettAnzeige aktuallisiern
	schachZug->zugBeginnen();
}

Figuren SpielerMensch::tauscheBauern(){
	return KOENIG;
}

SpielerMensch::~SpielerMensch(){
}
