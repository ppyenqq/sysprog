
#ifndef SYMTYPE
#define SYMTYPE
#include "../SymbolType/symboltype.h"
#include "../Symtab/SymbolItem.h"
#include "../Position/Position.h"

#endif

class Token {
public:
    Token();
    
    char* getValue();
    void setValue(char* value);
    
    Signtype getType();
    void setType(Signtype type);
    
    bool isEOF();
    const char* getTypeString();

    void setPosition(Position *pos);
    void setPosition(int row, int col);
    Position* getPosition();

    int getCol();
    int getRow();

    SymbolItem* getItem();
    void setItem(SymbolItem* itemSymtab);

    const char* toString();

private:
    char* value;
    Signtype type;
    Position* position;
    SymbolItem* itemSymtab;

    bool hasLexem();
    bool hasValue();
};

