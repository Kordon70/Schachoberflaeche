#include "SpielBeendet.h"


SpielBeendet::SpielBeendet(SchachLogik* logik) : QObject (0) {
	this->logik = logik;
	partieBeendet = new QWidget;
	partieBeendet->setWindowModality(Qt::ApplicationModal);
    partieBeendet->setWindowTitle(QObject::tr("Spiel beendet"));
	partieBeendet->setFixedSize(200, 120);


	QLabel* gewinner = ausgabe();
	QPushButton* ok = new QPushButton("OK");
	ok->setFixedWidth(100);
	QWidget::connect(ok,SIGNAL(clicked()), this, SLOT(schlieseBeendetFenster()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(gewinner,0, Qt::AlignCenter);
	layout->addWidget(ok, 0, Qt::AlignCenter);

    partieBeendet->setLayout(layout);
    partieBeendet->show();
}

QLabel* SpielBeendet::ausgabe() {
	switch(logik->ermittleSieger()) {
	case KEINE:
		return new QLabel("Spiel mit einem Unentschieden\n beendet.");
	case WEISS:
		return new QLabel(QString::fromStdWString(L"Spiel beendet.\nGewonnen hat weiß."));
	case SCHWARZ:
		return new QLabel("Spiel beendet.\nGewonnen hat schwarz.");
	}
}

void SpielBeendet::schlieseBeendetFenster() {
	partieBeendet->close();
}


SpielBeendet::~SpielBeendet() {
}
