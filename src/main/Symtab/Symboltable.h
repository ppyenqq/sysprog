/*
 * Symboltable.h
 *
 *  Created on: 02.05.2015
 *      Author: holger
 */

#include <iostream>
#include <cstdlib>

#include "Information.h"
#include "../SymbolType/symboltype.h"
#include "SymbolItem.h"

using namespace std;

#ifndef Symboltable_H_
#define Symboltable_H_

class Symboltable {
private:
    /*
     * Integer-Wert zur Array-Größe
     */
    static const int tableSize = 1024;

    /**
     * Size of the string buffer.
     */
    static const int stringMemorySize = 10000;
    /*
     * Die Hashtabelle, die für die
     * verkettete Liste verwendet wird
     */
    SymbolItem *hashTable[tableSize];
    /*
     * Struktur von einem Element
     * in der Stringtabelle
     */
    struct StringItem {
        char stringMemory[stringMemorySize];
        StringItem *next;
    };
    /*
     * Aufrufbares Element der Stringtabelle
     */
    StringItem *stringTable;
    /*
     * Pointer für die Stringspeicher
     */
    char *ptrStringMemory;
    /*
     * Counter, um zu sehen wieviel
     * im Stringspeicher schon belegt ist
     */
    int counterStringMemory;
public:
    /*
     * Konstruktor der Klasse
     */
    Symboltable();

    /*
     * Gibt die Länge eines Wortes zurück
     */
    int length(const char *lexem);

    /*
     * Vergleiche Lexem mit gespeicherten
     * Wort im Element
     */
    bool compare(const char *lexem1, const char *lexem2);

    /*
     * Erzeugt eine Adresse, wo der
     * das Element gespeichert wird.
     */
    int hashcode(const char *lexem, int length);

    /*
     * Ein Informationselement hinzufügen
     */
    SymbolItem *insert(const char *lexem);

    /*
     * Wert in Stringtabelle einfügen
     */
    char *insertStringTable(const char *lexem);

    /*
     * Suche nach dem Lexem in der Hashtabelle
     * und gibt Wert aus
     */
    SymbolItem *search(const char *lexem);

    /*
     *
     */
    void view();

    /*
     * Ausgabe was in der Stringtabelle steht
     */
    //void viewStringTable();

    /*
    * Gibt belegten Speicher von der Hashtabelle
    * frei
    */
    virtual ~Symboltable();
};


#endif /* Symboltable_H_ */
