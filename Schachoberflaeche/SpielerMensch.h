#pragma once

#include "zug.h"
#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"

class SpielerMensch : public SpielerBenachrichtigung
{

private:
	Zug* schachZug;

public:
	Figuren tauscheBauern();
	void duBistDran();
	SpielerMensch(Zug* schachZug);
	void spielBeendet();
	~SpielerMensch();
};

