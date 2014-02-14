#pragma once

#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"
#include "zug.h"
#include "../SpielBeendet.h"
#include "../FigurenWechsel.h"

class SpielerMensch : public SpielerBenachrichtigung
{

private:
	Zug* schachZug;
	Farbe spielFarbe;

public:
	Figuren tauscheBauern();
	void duBistDran();
	SpielerMensch(Zug* schachZug, Farbe spielFarbe);
	void spielBeendet();
	Farbe getSpielFarbe();
	~SpielerMensch();
};

