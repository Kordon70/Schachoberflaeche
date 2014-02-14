#include "SpielBeendet.h"


SpielBeendet::SpielBeendet() : QObject (0) {
	partieBeendet = new QWidget;
	partieBeendet->setWindowModality(Qt::ApplicationModal);
    partieBeendet->setWindowTitle(QObject::tr("Neues Spiel"));

	QLabel* gewinner = new QLabel("Gewonnen hat einer von beiden");
	QPushButton* ok = new QPushButton("OK");
	QWidget::connect(ok,SIGNAL(clicked()), this, SLOT(schlieseBeendetFenster()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(gewinner);
	layout->addWidget(ok);

    partieBeendet->setLayout(layout);
    partieBeendet->show();
}

void SpielBeendet::schlieseBeendetFenster() {
	partieBeendet->close();
}


SpielBeendet::~SpielBeendet() {
}
