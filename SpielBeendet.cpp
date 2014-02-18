#include "SpielBeendet.h"


SpielBeendet::SpielBeendet() : QObject (0) {
	partieBeendet = new QWidget;
	partieBeendet->setWindowModality(Qt::ApplicationModal);
    partieBeendet->setWindowTitle(QObject::tr("Spiel beendet"));
	partieBeendet->setFixedSize(200, 120);

	QLabel* gewinner = new QLabel("Spiel beendet. \n Gewonnen hat SCHWARZ."); //ToDo ausgeben wer wirklich gewonnen hat
	QPushButton* ok = new QPushButton("OK");
	ok->setFixedWidth(100);
	QWidget::connect(ok,SIGNAL(clicked()), this, SLOT(schlieseBeendetFenster()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(gewinner,0, Qt::AlignCenter);
	layout->addWidget(ok, 0, Qt::AlignCenter);

    partieBeendet->setLayout(layout);
    partieBeendet->show();
}

void SpielBeendet::schlieseBeendetFenster() {
	partieBeendet->close();
}


SpielBeendet::~SpielBeendet() {
}
