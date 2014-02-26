#include "newgamebutton.h"

newGameButton::newGameButton(Schachlogik* logik, Zug* schachZug, OberflaecheInterface* oberlaeche) :
    QObject(0) {
		this->schachZug = schachZug;
		this->logik = logik;
		this->oberlaeche = oberlaeche;
}

void newGameButton::openNewGameWindow() {
    neuePartie = new QWidget;
	neuePartie->setWindowModality(Qt::ApplicationModal);
	neuePartie->setWindowFlags(neuePartie->windowFlags() & ~Qt::WindowMaximizeButtonHint);
	neuePartie->setFixedSize(200,120);
    neuePartie->setWindowTitle(QObject::tr("Neues Spiel"));

    QPushButton* einSpieler = new QPushButton("1 Spieler");
	QWidget::connect(einSpieler,SIGNAL(clicked()), this, SLOT(startePartieGegenComputer()));
    QPushButton* zweiSpieler = new QPushButton("2 Spieler");
	QWidget::connect(zweiSpieler,SIGNAL(clicked()), this, SLOT(startePartieMitZweiSpieler()));
    QPushButton* fensterSchliesen = new QPushButton("Abbrechen");
	QWidget::connect(fensterSchliesen,SIGNAL(clicked()), this, SLOT(schlieseFenster()));
    
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(einSpieler);
    layout->addWidget(zweiSpieler);
	layout->addWidget(fensterSchliesen);

    neuePartie->setLayout(layout);
    neuePartie->show();
}

void newGameButton::startePartieGegenComputer() {
	new KuenstlicheIntelligenz();
}

void newGameButton::startePartieMitZweiSpieler() {
	logik->neustarten();
	SpielerMensch* spielerEins = new SpielerMensch(schachZug, WEISS);
	SpielerMensch* spielerZwei = new SpielerMensch(schachZug, SCHWARZ);
	logik->registriereSpieler(spielerEins->getSpielFarbe(),spielerEins);
	logik->registriereSpieler(spielerZwei->getSpielFarbe(),spielerZwei);
	spielerEins->setLogik(logik);
	spielerZwei->setLogik(logik);
	logik->starteSpiel();
	schlieseFenster();
	oberlaeche->oberflaecheAktualisieren();
}

void newGameButton::schlieseFenster() {
	neuePartie->close();
}

newGameButton::~newGameButton() {
	delete neuePartie;
}