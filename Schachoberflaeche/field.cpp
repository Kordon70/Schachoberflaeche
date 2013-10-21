#include "field.h"
#include <QtGui>

Field::Field(const QString color, const QPixmap* image, QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200,200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this->setGeometry(0,0,300,100);
    this->setStyleSheet(color);

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
