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

void Field::changePicture(QPixmap picture) {
    figure->setPixmap(picture);
    figure->show();
    figure->setAttribute(Qt::WA_DeleteOnClose);
}


Field::~Field()
{

}
