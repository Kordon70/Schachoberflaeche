#include "SpielerMensch.h"


SpielerMensch::SpielerMensch(void){
}

void SpielerMensch::duBistDran(){
	schachZug->zugBeginnen();
}

Figuren SpielerMensch::tauscheBauern(){
	return KOENIG;
}

SpielerMensch::~SpielerMensch(){
}
