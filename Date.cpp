#include "Date.h"

#include <iostream>

using namespace std;

bool Date :: czyJestPrzestepny()
{
    if (lata%400 ==0 || (lata %4==0 && lata %100 !=0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date :: ileDniMaMiesiac()
{
    if (miesiace ==2 && czyPrzystepny ==true)
    {

        if (dni <= 29)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(miesiace == 2 && czyPrzystepny == false)
    {

        if(dni <= 28)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else if((czyPrzystepny==false || czyPrzystepny == true) && (1<=miesiace<2 || 3<=miesiace<=12))
    {
        if (miesiace == 1 || miesiace ==3 || miesiace == 5 || miesiace == 7 || miesiace ==8 || miesiace ==10 || miesiace ==12)
        {
            if(dni <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        if(miesiace==4 || miesiace ==6 || miesiace == 9 || miesiace ==11)
        {
            if(dni <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }


        }
    }
    else
    {
        return false;
    }

}





int Date :: countLeapYears()
{
    int podanyRok = lata;
    if(miesiace <=2)
    {
        podanyRok -=1;
    }
    int wynik = podanyRok/4 - (podanyRok/100)+podanyRok/400;
    return wynik;
}



Date :: Date()
{
        dni = 0;
        miesiace = 0;
        lata = 0;
}



Date :: Date(int wpiszDzien, int wpiszMiesiac, int wpiszLata): czyPrzystepny(czyJestPrzestepny())
{
        dni =wpiszDzien;
        miesiace =wpiszMiesiac;
        lata = wpiszLata;
        liczbaLatPrzestepnych = countLeapYears();

}


bool Date :: PobierzCzyRokJestPrzestepny()
{
    return czyPrzystepny;
}



int Date :: pobierzLiczbeLatPrzestepnych()
{
    return liczbaLatPrzestepnych;
}







