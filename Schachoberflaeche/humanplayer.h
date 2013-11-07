#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "../../SchachLogik/SchachLogik/src/SpielerBenachrichtigung.h"

class HumanPlayer : public SpielerBenachrichtigung
{
public:
    HumanPlayer();
    void naechsterZug(Farbe farbe);
};

#endif // HUMANPLAYER_H
