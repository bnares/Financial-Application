#include <iostream>
#include "AuxiliaryMethods.h"


using namespace std;

char AuxiliaryMethods::getChar()
{
    string tekst;
    char znak = {0};
    while (true)
    {
        getline(cin, tekst);
        if(tekst.length()>1)
        {
            cout<<"wpisz pojedynczy znak"<<endl;
        }
        else if(tekst.length() ==1)
        {
            znak = tekst[0];
            break;
        }
        else
        {
            cout<<"Nie wybrales zadnej opcji"<<endl;
        }
    }
    return znak;
}



int AuxiliaryMethods :: convertStringToNUmber(string textToConvert)
{
    stringstream ss;
    int number;

    ss <<textToConvert;
    ss>>number;
    return number;
}


string AuxiliaryMethods :: convertNumberToString(int numberToConvert)
{
    stringstream ss;
    string text;
    ss<<numberToConvert;
    ss>>text;
    return text;

}


string AuxiliaryMethods :: getText()
{
    string text;
    cin.sync();
    cin.clear();
    getline(cin, text);
    return text;
}
