#pragma once

#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "Zug.h"

class Oberflaeche
{
public:
	Oberflaeche(SchachLogik* logik, Zug* schachzug);
	~Oberflaeche(void);
};

