#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "../../SchachLogik/SchachLogik/src/Beobachter.h"

class HumanPlayer : public Beobachter
{
public:
    HumanPlayer();
    void naechsterZug(Farbe farbe);
};

#endif // HUMANPLAYER_H
