#include "Date.h"





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

        if (dni <= 29 && dni>=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(miesiace == 2 && czyPrzystepny == false)
    {

        if(dni <= 28 && dni>=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if((czyPrzystepny==false || czyPrzystepny == true) && (1<=miesiace<2 || 3<=miesiace<=12))
    {
        if (miesiace == 1 || miesiace ==3 || miesiace == 5 || miesiace == 7 || miesiace ==8 || miesiace ==10 || miesiace ==12)
        {
            if(dni <= 31 && dni>=1)
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
            if(dni <= 30 && dni>=1)
            {
                return true;
            }
            else
            {
                return false;
            }


        }
    }
    if(miesiace>12 || dni >31 || dni<=0 || miesiace<=0)
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



int Date :: getDateAsNumber()
{
    stringstream ssy;
    ssy<<lata;
    stringstream ssm;
    ssm<<miesiace;
    stringstream ssd;
    ssd<<dni;

    string stringYear;
    ssy>>stringYear;
    string stringMonth;
    ssm>>stringMonth;
    string stringDay;
    ssd>>stringDay;

    if(miesiace<=9)
    {
        stringMonth = "0"+stringMonth;
    }
    if(dni<=9)
    {
        stringDay = "0"+stringDay;
    }
    string stringNumber = stringYear+stringMonth+stringDay;

    int dayNumber;
    stringstream ss(stringNumber);
    ss>>dayNumber;
    return dayNumber;




}



int Date :: getTodayDateAsNumber()
{
    SYSTEMTIME date;
    GetLocalTime(&date);
    int year = date.wYear;
    int month = date.wMonth;
    int day = date.wDay;

    stringstream ssy;
    ssy<<year;
    stringstream ssm;
    ssm<<month;
    stringstream ssd;
    ssd<<day;

    string stringYear;
    ssy>>stringYear;
    string stringMonth;
    ssm>>stringMonth;
    string stringDay;
    ssd>>stringDay;


    ssy>>stringYear;
    ssm>>stringMonth;
    ssd>>stringDay;

    if(month<=9)
    {
        stringMonth = "0"+stringMonth;
    }
    if(day<=9)
    {
        stringDay = "0"+stringDay;
    }
    string stringNumber = stringYear+stringMonth+stringDay;

    int dayNumber;
    stringstream ss(stringNumber);
    ss>>dayNumber;
    return dayNumber;
}





void Date :: setDays(int days)
{
    dni = days;
}

void Date :: setYear(int yearNumber)
{
    lata = yearNumber;
}

void Date :: setMonth(int month)
{
    miesiace = month;
}




int Date :: countingDaysInSpecificMonth()
{
    if(miesiace == 1 || miesiace == 3 || miesiace == 5 || miesiace==7 || miesiace==8 || miesiace == 10 || miesiace ==12)
    {
        return 31;
    }

    if(miesiace ==4 || miesiace == 6 || miesiace == 9 || miesiace ==11)
    {
        return 30;
    }

    if(czyPrzystepny == true && miesiace ==2)
    {
        return 29;
    }

    if(czyPrzystepny = false && miesiace ==2)
    {
        return 28;
    }
}







