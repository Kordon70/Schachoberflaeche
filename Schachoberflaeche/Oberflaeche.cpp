#include "Oberflaeche.h"


Oberflaeche::Oberflaeche(SchachLogik* logik, Zug* schachzug)
{
	this->logik = logik;
	this->schachZug = schachzug;
	this->schachZug->setzteOberflaeche(this);
}

void Oberflaeche::oberflaecheErstellen() {
	chess = new SchachbrettAnzeige(logik, schachZug);
	QVBoxLayout* verticalLayout = chess->initializeChessField();
	//buttons erstellen und zu layout hinzufügen
	QPushButton* buttonNeuePartie = new QPushButton;
    buttonNeuePartie->setText("Neue Partie");
	QPushButton* buttonAnzeigen = new QPushButton;
    buttonAnzeigen->setText("Anzeigen");

	QHBoxLayout* horizonatalButtonLayout = new QHBoxLayout;
	horizonatalButtonLayout->addWidget(buttonNeuePartie);
	horizonatalButtonLayout->addWidget(buttonAnzeigen);
	
	verticalLayout->addLayout(horizonatalButtonLayout);
	mainWidget.setLayout(verticalLayout);

	//events verlinken
	newGameButton* neuePartieFenster = new newGameButton(logik, schachZug);
    QWidget::connect(buttonNeuePartie,SIGNAL(clicked()),neuePartieFenster, SLOT(openNewGameWindow()));
	QWidget::connect(buttonAnzeigen,SIGNAL(clicked()),chess, SLOT(startNewGame()));

	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();
}

void Oberflaeche::oberflaecheAktualisieren() {
	chess->aktualisiereSchachfeld();
}

Oberflaeche::~Oberflaeche(void)
{
}
