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
	newGameButton* ngb = new newGameButton;
    QWidget::connect(buttonNeuePartie,SIGNAL(clicked()),ngb, SLOT(openNewGameWindow()));
	QWidget::connect(buttonAnzeigen,SIGNAL(clicked()),chess, SLOT(startNewGame()));

	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();

	spielMitZweiSpielernStarten();
}

void Oberflaeche::oberflaecheAktualisieren() {
	chess->aktualisiereSchachfeld();
}

void Oberflaeche::spielMitZweiSpielernStarten() {
	SpielerBenachrichtigung* spielerEins = new SpielerMensch(schachZug);
	SpielerBenachrichtigung* spielerZwei = new SpielerMensch(schachZug);
	logik->registriereSpieler(WEISS,spielerEins);
	logik->registriereSpieler(SCHWARZ,spielerZwei);
	logik->starteSpiel();
}

Oberflaeche::~Oberflaeche(void)
{
}
