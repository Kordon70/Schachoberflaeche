#include "SpielBeendet.h"


SpielBeendet::SpielBeendet() : QObject (0) {
	partieBeendet = new QWidget;
	partieBeendet->setWindowModality(Qt::ApplicationModal);
    partieBeendet->setWindowTitle(QObject::tr("Neues Spiel"));

    QVBoxLayout* layout = new QVBoxLayout;

	QLabel* gewinner = new QLabel("Gewonnen hat einer von beiden");

	layout->addWidget(gewinner);

    QPushButton* ok = new QPushButton("OK");
	QWidget::connect(ok,SIGNAL(clicked()), this, SLOT(schlieseBeendetFenster()));
	layout->addWidget(ok);

    partieBeendet->setLayout(layout);
    partieBeendet->show();
}

void SpielBeendet::schlieseBeendetFenster() {
	partieBeendet->close();
}


SpielBeendet::~SpielBeendet()
{
}
