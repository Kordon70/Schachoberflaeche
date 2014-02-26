#ifndef SCHACHFELD_H
#define SCHACHFELD_H

#include <QFrame>
#include <QLabel>

#include "../../SchachLogik/SchachLogik/src/Farbe.h"
#include "../../SchachLogik/SchachLogik/src/Figur.h"
#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"

#include "Zug.h"

class QDragEnterEvent;
class QDropEvent;

/**
	Ein Schachfeld mit einer Hindergundfarbe und einem Bild mit der Figur 
	die auf dem Feld steht.

    @author Arne Maier
*/

 class Schachfeld: public QFrame
{
    Q_OBJECT
private:

	Schachlogik* logik;
	Zug* schachZug;
    QLabel* bild;
	QLabel* altesBild;
	Position* positionDesFeldes;
	QPixmap figureToPicture();

	void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);

public:
/**
	Erzeugt ein Schachfeld Objekt.

	@param logik Schachlogik die für den Spielablauf verantwortlich ist.
	@param schachZug Zug der die Bewegungen der Figuren auf dem Feld registriert.
	@param positionDesFeldes Position des einzelen Feld auf dem ganzen Schachfeld.
*/
	Schachfeld(Schachlogik* logik, Zug* schachZug, Position* positionDesFeldes);
    ~Schachfeld();

/**
	Ändert das Bild des Schachfeldes in dass der Figur die laut Logik auf dem Feld steht.
*/
	void aendereBild();

};

#endif // SCHACHFELD_H
