#ifndef CHESSFIELD_H
#define CHESSFIELD_H

#include <field.h>
#include <vector>

using namespace std;

class chessField
{
private:
    vector<vector<Field> > chessFiedVector;
public:
    chessField();
};

#endif // CHESSFIELD_H
