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
	//buttons erstellen und zu layout hinzuf�gen
	QPushButton* buttonNeuePartie = new QPushButton;
    buttonNeuePartie->setText("Neue Partie");
	QPushButton* buttonZugZurueck = new QPushButton;
	buttonZugZurueck->setText("Zug zur�ck");
	QPushButton* buttonEnde = new QPushButton;
    buttonEnde->setText("Beenden");

	QHBoxLayout* horizonatalButtonLayout = new QHBoxLayout;
	horizonatalButtonLayout->addWidget(buttonNeuePartie);
	horizonatalButtonLayout->addWidget(buttonZugZurueck);
	
	verticalLayout->addLayout(horizonatalButtonLayout);
	mainWidget.setLayout(verticalLayout);

	//events verlinken
	neuePartieFenster = new newGameButton(logik, schachZug, this);
    QWidget::connect(buttonNeuePartie,SIGNAL(clicked()),neuePartieFenster, SLOT(openNewGameWindow()));
	//QWidget::connect(buttonZugZurueck,SIGNAL(clicked()),chess, SLOT(startNewGame())); ToDO �berpr�fen ob irgendwas l�schen
	QWidget::connect(buttonZugZurueck,SIGNAL(clicked()),chess, SLOT(zugZurueck()));

	QWidget::connect(&mainWidget,SIGNAL(QCloseEvent), neuePartieFenster, SLOT(schlieseFenster()));

	mainWidget.setWindowTitle(QObject::tr("Schach"));
    mainWidget.show();
}

void Oberflaeche::oberflaecheAktualisieren() {
	chess->aktualisiereSchachfeld();
}

Oberflaeche::~Oberflaeche(void)
{
}
