#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>


using namespace std;

class AuxiliaryMethods
{
    public:
        static char getChar();
        static int convertStringToNUmber(string textToConvert);
        static string convertNumberToString(int numberToConvert);
        static string getText();
        static int getNumber();
        static float convertStringToFloatNumber(string stringFloat);
};



#endif // METODYPOMOCNICZE_H
