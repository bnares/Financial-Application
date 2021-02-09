#ifndef DATE_H
#define DATE_H


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

};




#endif // DATE_H
