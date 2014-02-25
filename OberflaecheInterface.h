#ifndef OBERFLAECHEINTERFACE_H
#define OBERFLAECHEINTERFACE_H

/**
	Interface des Hauptfensters.

    @author Arne Maier
*/

class OberflaecheInterface
{
public:
	virtual void oberflaecheErstellen() = 0;
/**
	Aktualisiert das Schachfeld, sowie die Anzeige des Spielers der an der Reihe ist.
*/
	virtual void oberflaecheAktualisieren() = 0;
	virtual ~OberflaecheInterface() {};
};

#endif // OBERFLAECHEINTERFACE_H