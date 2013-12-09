#ifndef OBERFLAECHEINTERFACE_H
#define OBERFLAECHEINTERFACE_H


class OberflaecheInterface
{
public:
	virtual void oberflaecheErstellen() = 0;
	virtual void oberflaecheAktualisieren() = 0;
	virtual ~OberflaecheInterface(void) {};

};

#endif // OBERFLAECHEINTERFACE_H