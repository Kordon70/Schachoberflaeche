
#include <QApplication>
#include "../../SchachLogik/SchachLogik/src/SchachLogik.h"
#include "Zug.h"
#include "Oberflaeche.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	SchachLogik* logik = new SchachLogik();
	Zug* zugDurchfruehren = new Zug(logik);
	Oberflaeche* gui = new Oberflaeche(logik, zugDurchfruehren);
	gui->oberflaecheErstellen();

    return app.exec();
}