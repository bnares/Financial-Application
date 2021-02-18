#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


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
        static bool isNumber(vector <string> text);
        static bool findDash(string text);
        static vector <string> createVectorFromDateWords(string date);
};



#endif // METODYPOMOCNICZE_H
