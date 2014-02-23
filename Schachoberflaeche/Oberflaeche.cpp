#include "Oberflaeche.h"
#include <QTextCodec>

Oberflaeche::Oberflaeche(SchachLogik* logik, Zug* schachzug)
{
	this->logik = logik;
	this->schachZug = schachzug;
	this->schachZug->setzteOberflaeche(this);
}

void Oberflaeche::oberflaecheErstellen() {
	chess = new SchachbrettAnzeige(logik, schachZug);	
	QPushButton* buttonNeuePartie = new QPushButton("Neue Partie");
	QPushButton* buttonZugZurueck = new QPushButton(QString::fromStdWString(L"Zug zurück"));
	QHBoxLayout* horizonatalButtonLayout = new QHBoxLayout;
	horizonatalButtonLayout->addWidget(buttonNeuePartie);
	horizonatalButtonLayout->addWidget(buttonZugZurueck);
	
	QVBoxLayout* verticalLayout = chess->initializeChessField();
	verticalLayout->addLayout(horizonatalButtonLayout);
	mainWidget.setLayout(verticalLayout);

	neuePartieFenster = new newGameButton(logik, schachZug, this);
    QWidget::connect(buttonNeuePartie,SIGNAL(clicked()),neuePartieFenster, SLOT(openNewGameWindow()));
	QWidget::connect(buttonZugZurueck,SIGNAL(clicked()),chess, SLOT(zugZurueck()));

	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();
}

void Oberflaeche::oberflaecheAktualisieren() {
	chess->aktualisiereSchachfeld();
}

Oberflaeche::~Oberflaeche() {
}
