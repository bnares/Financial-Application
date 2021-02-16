
#include "AuxiliaryMethods.h"




char AuxiliaryMethods::getChar()
{
    string tekst;
    char znak = {0};
    while (true)
    {
        getline(cin, tekst);
        if(tekst.length()>1)
        {
            cout<<"Write single Char"<<endl;
        }
        else if(tekst.length() ==1)
        {
            znak = tekst[0];
            break;
        }
        else
        {
            cout<<"You haven't choswn any option"<<endl;
        }
    }
    return znak;
}



float AuxiliaryMethods :: convertStringToFloatNumber(string stringFloat)
{
    stringstream ss;
    float numberFloat = 0.0;
    ss<<stringFloat;
    ss>>numberFloat;
    return numberFloat;
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


int AuxiliaryMethods :: getNumber()
{

    int number;
    cin.clear();
    cin.sync();
    cin>>number;
    return number;
}
