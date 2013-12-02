#pragma once

#include "zug.h"
#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"

class SpielerMensch : SpielerBenachrichtigung
{

private:
	Zug* schachZug;

public:
	Figuren tauscheBauern();
	void duBistDran();
	SpielerMensch();
	~SpielerMensch();
};

