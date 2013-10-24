#ifndef CHESSFIELD_H
#define CHESSFIELD_H

#include <field.h>
#include <../../SchachLogik/src/Farbe.h>
#include <vector>
#include <QHBoxLayout>
#include <QVBoxLayout>

using namespace std;

class chessField
{
private:
    vector<vector<Field*>* > chessFiedVector;
    QVBoxLayout* verticalLayout;

    vector<Field* >* initializeHorizontalRow(int row);
    vector<Field* >* emptyHorizontalRowStartsWithBlack();
    vector<Field* >* emptyHorizontalRowStartsWithWhite();
    Field* createFieldAndAddToLayout(QHBoxLayout* layout, Farbe fieldColor);
public:
    chessField();
    QVBoxLayout* initializeChessField();
};

#endif // CHESSFIELD_H
