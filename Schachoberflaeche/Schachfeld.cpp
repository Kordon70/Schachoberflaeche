#include "Schachfeld.h"
#include <QtGui>

Schachfeld::Schachfeld(SchachLogik* logik, Zug* schachZug, Position* positionDesFeldes, QWidget *parent)
    : QFrame(parent) {
		int size = 70;
	this->logik = logik;
	this->schachZug = schachZug;
	this->positionDesFeldes = positionDesFeldes;
	setFixedSize(size,size);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this->setGeometry(0,0,size,size);
	Farbe feldFarbe = logik->getSpielfeld()->getFarbeDesFeldes(*positionDesFeldes);
    if (feldFarbe == WEISS) {
        this->setStyleSheet("background-color:white;");
    } else if (feldFarbe == SCHWARZ) {
        this->setStyleSheet("background-color:grey;");
	}
	altesBild = 0;
	bild = new QLabel(this);
	bild->setPixmap(QPixmap(":/images/empty.png"));
	bild->setAttribute(Qt::WA_DeleteOnClose);
}

void Schachfeld::aendereBild() {
	if(altesBild != 0) {
		delete altesBild;
	}
	altesBild = bild;
	bild = new QLabel(this);
	bild->setPixmap(figureToPicture());
	bild->show();
	bild->setAttribute(Qt::WA_DeleteOnClose);
}

QPixmap Schachfeld::figureToPicture() {
	QString bildName;
	pair<FigurTyp, Farbe> figur = logik->getSpielfeld()->getFigurAnPosition(*positionDesFeldes);
	switch (figur.first) {
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
		return QPixmap(":/images/empty.png");
	}
	if(figur.second==SCHWARZ) {
		bildName += "schwarz.png";
	} else {
		bildName += "weis.png";
	}
	return QPixmap(bildName);
}

void Schachfeld::dragEnterEvent(QDragEnterEvent *event) {
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

 void Schachfeld::dragMoveEvent(QDragMoveEvent *event) {
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

 void Schachfeld::dropEvent(QDropEvent *event) {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

         QPixmap pixmap;
         QPoint offset;
         dataStream >> pixmap >> offset;

         QLabel *newIcon = new QLabel(this);
         newIcon->setPixmap(pixmap);
         newIcon->move(event->pos() - offset);
         newIcon->setAttribute(Qt::WA_DeleteOnClose);
		 
     } else {
         event->ignore();
     }

	 schachZug->beendeZug(positionDesFeldes);
 }

 void Schachfeld::mousePressEvent(QMouseEvent *event) {
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
         child->setPixmap(pixmap);
     }
 }


Schachfeld::~Schachfeld() {
}
