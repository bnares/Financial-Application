#ifndef DATE_H
#define DATE_H
//#include <time.h>
//#include <ctime>
#include <windows.h>
#include <sstream>


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

};




#endif // DATE_H
