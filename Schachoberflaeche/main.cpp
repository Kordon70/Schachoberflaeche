#include "field.h"
#include <QApplication>
#include <QHBoxLayout>
#include "../../SchachLogik/src/Logik.h"
#include "humanplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWidget;
    QHBoxLayout* horizonatalLayout = new QHBoxLayout;
    QPixmap* kingWhite = new QPixmap(":/images/King-white_256x256_32.png");
    horizonatalLayout->addWidget(new Field("background-color:grey;", kingWhite));
    horizonatalLayout->addWidget(new Field("background-color:white;", kingWhite));
    horizonatalLayout->addWidget(new Field("background-color:grey;", kingWhite));
    horizonatalLayout->addWidget(new Field("background-color:white;", kingWhite));

    QHBoxLayout* horizonatalLayout2 = new QHBoxLayout;
    horizonatalLayout2->addWidget(new Field("background-color:white;"));
    horizonatalLayout2->addWidget(new Field("background-color:grey;", kingWhite));
    horizonatalLayout2->addWidget(new Field("background-color:white;", kingWhite));


    Field* d2 = new Field("background-color:yellow;", kingWhite);
    d2->changePicture(QPixmap(":/images/Yanni"));


    horizonatalLayout2->addWidget(d2);

    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->addLayout(horizonatalLayout);
    verticalLayout->addLayout(horizonatalLayout2);

    HumanPlayer* playerWhite = new HumanPlayer();
    HumanPlayer* playerBlack = new HumanPlayer();

    mainWidget.setLayout(verticalLayout);
    mainWidget.setWindowTitle(QObject::tr("Schach"));

    mainWidget.show();
    return app.exec();
}

QVBoxLayout initializeChessfield() {

}
