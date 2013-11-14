#include "field.h"
#include <QtGui>

Field::Field(const Farbe backgroundColor, const QPixmap* image, QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(100,100);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this->setGeometry(0,0,300,100);
    if (backgroundColor == WEISS) {
        this->setStyleSheet("background-color:grey;");
    } else if (backgroundColor == SCHWARZ) {
        this->setStyleSheet("background-color:white;");
    }

    figure = new QLabel(this);
}

void Field::changePicture(pair<Figuren, Farbe>* figur) {
	const QPixmap* bild = figureToPicture(figur);
	figure->setPixmap(*bild);
	figure->show();
	figure->setAttribute(Qt::WA_DeleteOnClose);
}

QPixmap* Field::figureToPicture(pair<Figuren, Farbe>* figur) {
	QString bild;
	switch (figur->first)
	{
	case KOENIG:
		bild = ":/images/Koenig-";
		break;
	case DAME:
		bild = ":/images/Dame-";
		break;
	case BAUER:
		bild = ":/images/Bauer-";
		break;
	case TURM:
		bild = ":/images/Turm-";
		break;
	case LAEUFER:
		bild = ":/images/Laeufer-";
		break;
	case SPRINGER:
		bild = ":/images/Springer-";
		break;
	default:
		return new QPixmap(":/images/empty.png");
	}
	if(figur->second==SCHWARZ) {
		bild += "schwarz.png";
	} else {
		bild += "weis.png";
	}
	return new QPixmap(bild);
}


Field::~Field()
{

}
