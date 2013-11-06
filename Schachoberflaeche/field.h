#ifndef SCHACHOBERFLAECHE_H
#define SCHACHOBERFLAECHE_H

#include "../../SchachLogik/SchachLogik/src/Farbe.h"
#include <QFrame>
#include <QLabel>
#include "../../SchachLogik/SchachLogik/src/Figur.h"

class Field: public QFrame
{
    Q_OBJECT
private:
    QLabel* figure;
	QPixmap* figureToPicture(pair<Figuren, Farbe>* figur);

public:

    Field(const Farbe backgroundColor, const QPixmap* image = 0, QWidget *parent = 0);
    ~Field();
	void changePicture(pair<Figuren, Farbe>* figur);


};

#endif // SCHACHOBERFLAECHE_H
