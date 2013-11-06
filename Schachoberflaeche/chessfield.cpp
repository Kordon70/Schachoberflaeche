#include "chessfield.h"

chessField::chessField() {
        verticalLayout = new QVBoxLayout;
}

QVBoxLayout* chessField::initializeChessField() {
    for (int row = 0; row < 8; row++) {
        chessFiedVector.push_back(initializeHorizontalRow(row));
    }
    return verticalLayout;
}

vector<Field* >* chessField::initializeHorizontalRow(int row) {
    switch(row%2){
    case 0:
        return emptyHorizontalRowStartsWithWhite();
    case 1:
        return emptyHorizontalRowStartsWithBlack();
        break;
    default:
        break;
    }
    return emptyHorizontalRowStartsWithBlack();
}

vector<Field* >* chessField::emptyHorizontalRowStartsWithBlack() {
    vector<Field* >* result = new vector<Field*>();
    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    for(int i = 0; i < 8; i++) {
        if (i%2==0) {
            result->push_back(createFieldAndAddToLayout(horizontalLayout, SCHWARZ));
        } else {
            result->push_back(createFieldAndAddToLayout(horizontalLayout, WEISS));
        }
    }
    verticalLayout->addLayout(horizontalLayout);
    return result;
}

vector<Field* >* chessField::emptyHorizontalRowStartsWithWhite() {
    vector<Field* >* result = new vector<Field*>();
    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    for(int i = 0; i < 8; i++) {
        if (i%2==0) {
			result->push_back(createFieldAndAddToLayout(horizontalLayout, WEISS));
        } else {
            result->push_back(createFieldAndAddToLayout(horizontalLayout, SCHWARZ));
        }
    }
    verticalLayout->addLayout(horizontalLayout);
    return result;
}

Field* chessField::createFieldAndAddToLayout(QHBoxLayout* layout, Farbe fieldColor) {
	Field* result = new Field(fieldColor, new QPixmap(":/images/King-white_256x256_32.png"));
    layout->addWidget(result);
    return result;
}

void chessField::startNewGame() {

}

void chessField::setFiguresOnTheChessfield(SchachBrettAusgabe* logikSchachbrett) {
	for(unsigned row = 0; row < 8; row++) {
		for(unsigned column = 0; column < 8; column++) {
			chessFiedVector[row]->at(column)->changePicture(&logikSchachbrett->getFigurAnPosition(Position(column, row)));
		}
	}
}
