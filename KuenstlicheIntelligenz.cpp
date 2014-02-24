#include "KuenstlicheIntelligenz.h"


KuenstlicheIntelligenz::KuenstlicheIntelligenz() {
	kiFehler = new QDialog();
	kiFehler->setWindowModality(Qt::ApplicationModal);
	kiFehler->setWindowFlags(kiFehler->windowFlags() & ~Qt::WindowContextHelpButtonHint & 
		~Qt::WindowCloseButtonHint);
	kiFehler->setFixedSize(200,100);
	kiFehler->setWindowTitle("Keine KI vorhanden");

	QLabel* text = new QLabel(QString::fromStdWString(L"Leider gibt es keine künstliche\nIntelligenz."));
	QPushButton* ok = new QPushButton("OK");
	QWidget::connect(ok, SIGNAL(clicked()), this, SLOT(close()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(text);
	layout->addWidget(ok);

	kiFehler->setLayout(layout);
	kiFehler->show();
}


KuenstlicheIntelligenz::~KuenstlicheIntelligenz() {
	delete kiFehler;
}

void KuenstlicheIntelligenz::close() {
	kiFehler->close();
}
