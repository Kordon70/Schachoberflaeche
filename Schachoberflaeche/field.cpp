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
        this->setStyleSheet("background-color:white;");
    } else if (backgroundColor == SCHWARZ) {
        this->setStyleSheet("background-color:grey;");
    }

    figure = new QLabel(this);
    if (image != 0) {
        figure->setPixmap(*image);
    }
    figure->move(0, 0);
    figure->show();
    figure->setAttribute(Qt::WA_DeleteOnClose);
}

void Field::changePicture(pair<Figuren, Farbe>* figur) {
	const QPixmap* bild = figureToPicture(figur->first);
	figure->setPixmap(*bild);
	figure->show();
	figure->setAttribute(Qt::WA_DeleteOnClose);
}

QPixmap* Field::figureToPicture(Figuren figur) {
	switch (figur)
	{
	case KOENIG:
		return new QPixmap();
	case DAME:
	case BAUER:
	case TURM:
	case LAEUFER:
	case SPRINGER:
	default:
		return new QPixmap(":/images/King-white_256x256_32.png");
	}
}


Field::~Field()
{

}
