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


bool AuxiliaryMethods::isNumber(vector <string> text)
{
    for(vector <string>::iterator it = text.begin(); it!=text.end(); it++)
    {
        for(int i=0; i<(*it).length(); i++)
        {
            if(isdigit((*it)[i])==false)
            {
                return false;
            }
        }
    }
    return true;
}


bool AuxiliaryMethods::findDash(string text)
{
    size_t iterFirst = text.find("-");
    size_t iterSecond = text.find(5,text.length(),"-");
    if(iterFirst == 4 && iterSecond == 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}


vector <string> AuxiliaryMethods::createVectorFromDateWords(string date)
{
        vector <string> words;
        stringstream ss(date);
        string token;
        while(getline(ss,token,'-'))
        {
            words.push_back(token);
        }
        return words;
}



float AuxiliaryMethods::convertStringToFloatNumber(string stringFloat)
{
    stringstream ss;
    float numberFloat = 0.0;
    ss<<stringFloat;
    ss>>numberFloat;
    return numberFloat;
}



int AuxiliaryMethods::convertStringToNUmber(string textToConvert)
{
    stringstream ss;
    int number;


    ss <<textToConvert;
    ss>>number;
    return number;
}


string AuxiliaryMethods::convertNumberToString(int numberToConvert)
{
    stringstream ss;
    string text;
    ss<<numberToConvert;
    ss>>text;
    return text;

}


string AuxiliaryMethods::getText()
{
    string text;
    cin.sync();
    cin.clear();
    getline(cin, text);
    return text;
}


int AuxiliaryMethods::getNumber()
{

    int number;
    cin.clear();
    cin.sync();
    cin>>number;
    return number;
}
