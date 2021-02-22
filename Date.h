#ifndef DATE_H
#define DATE_H
//#include <time.h>
//#include <ctime>
#include <windows.h>
#include <sstream>
#include <iostream>

using namespace std;


class Date
{
    public:
    int dni;
    int miesiace;
    int lata;
    bool czyPrzystepny;
    int liczbaLatPrzestepnych;
    bool czyJestPrzestepny();
    bool ileDniMaMiesiac();
    int countLeapYears();
    Date();
    Date(int wpiszDzien, int wpiszMiesiac, int wpiszLata);
    bool PobierzCzyRokJestPrzestepny();
    int pobierzLiczbeLatPrzestepnych();
    int getTodayDateAsNumber();
    void setDays(int days);
    void setYear(int yearNumber);
    void setMonth(int month);
    int countingDaysInSpecificMonth();
    int getDateAsNumber();
    static string getTodayDate();
    int getYear()
    {
        return lata;
    };

};




#endif // DATE_H
