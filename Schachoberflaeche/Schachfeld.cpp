#include "Schachfeld.h"
#include <QtGui>

Schachfeld::Schachfeld(SchachLogik* logik, Zug* schachZug, Position* positionDesFeldes, QWidget *parent)
    : QFrame(parent)
{
	

	this->logik = logik;
	this->schachZug = schachZug;
	this->positionDesFeldes = positionDesFeldes;
    setMinimumSize(100,100);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this->setGeometry(0,0,300,100);
	Farbe feldFarbe = logik->getSpielfeld().getFeldFarbe(positionDesFeldes->getZeile(), positionDesFeldes->getSpalte());
    if (feldFarbe == WEISS) {
        this->setStyleSheet("background-color:white;");
    } else if (feldFarbe == SCHWARZ) {
        this->setStyleSheet("background-color:grey;");
	}
}

void Schachfeld::aendereBild() {
	bild = new QLabel(this);
	QPixmap* pixmapBild  = figureToPicture();
	bild->setPixmap(*pixmapBild);
	bild->show();
	bild->setAttribute(Qt::WA_DeleteOnClose);
}

QPixmap* Schachfeld::figureToPicture() {
	QString bildName;
	pair<Figuren, Farbe> figur = logik->getSpielfeld().getFigurAnPosition(*positionDesFeldes);
	switch (figur.first)
	{
	case KOENIG:
		bildName = ":/images/Koenig-";
		break;
	case DAME:
		bildName = ":/images/Dame-";
		break;
	case BAUER:
		bildName = ":/images/Bauer-";
		break;
	case TURM:
		bildName = ":/images/Turm-";
		break;
	case LAEUFER:
		bildName = ":/images/Laeufer-";
		break;
	case SPRINGER:
		bildName = ":/images/Springer-";
		break;
	default:
		//return new QPixmap(":/images/empty.png");
		return new QPixmap(":/images/red.png");
	}
	if(figur.second==SCHWARZ) {
		bildName += "schwarz.png";
	} else {
		bildName += "weis.png";
	}
	return new QPixmap(bildName);
}

void Schachfeld::dragEnterEvent(QDragEnterEvent *event)
 {
	 if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }

 void Schachfeld::dragMoveEvent(QDragMoveEvent *event)
 {
	 schachZug->beginneZug(positionDesFeldes);
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }

 void Schachfeld::dropEvent(QDropEvent *event)
 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

         QPixmap pixmap;
         QPoint offset;
         dataStream >> pixmap >> offset;

         QLabel *newIcon = new QLabel(this);
         newIcon->setPixmap(pixmap);
         newIcon->move(event->pos() - offset);
         newIcon->show();
         newIcon->setAttribute(Qt::WA_DeleteOnClose);
		 
         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }

	 schachZug->beendeZug(positionDesFeldes);
 }

 void Schachfeld::mousePressEvent(QMouseEvent *event)
 {
     QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
     if (!child)
         return;

     QPixmap pixmap = *child->pixmap();

     QByteArray itemData;
     QDataStream dataStream(&itemData, QIODevice::WriteOnly);
     dataStream << pixmap << QPoint(event->pos() - child->pos());

     QMimeData *mimeData = new QMimeData;
     mimeData->setData("application/x-dnditemdata", itemData);

     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);
     drag->setPixmap(pixmap);
     drag->setHotSpot(event->pos() - child->pos());

     QPixmap tempPixmap = pixmap;
     QPainter painter;
     painter.begin(&tempPixmap);
     painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
     painter.end();

     child->setPixmap(tempPixmap);

     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
         child->close();
     else {
         child->show();
         child->setPixmap(pixmap);
     }
 }


Schachfeld::~Schachfeld()
{
	// f->close(); //löschen
}
