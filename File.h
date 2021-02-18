#ifndef FILE_H


#define FILE_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Date.h"
#include <algorithm>
#include <windows.h>


using namespace std;

class File
{
    protected:
    string FILE_NAME;
    int idNumberOfUser;
    int idNumberOfTheLastActivity;
    int findIdNumberOfTheLastActivity();
    void setIdNumberOfTheLastActivity(int newLastNumberActivity);
    CMarkup xml;

    string modifyFileName(string fileName);
    string changeCommaToDot(string number);
    string createStringNumberFromStringVector(vector <string> data);
public:
    File(string fileName, int userId)
    : FILE_NAME(fileName), idNumberOfUser(userId)
    {
        idNumberOfTheLastActivity = findIdNumberOfTheLastActivity();
    };

    void addToFile();
    int getIdNumberOfTheLastActivity();
    vector <string> createVectorFromDateWords(string date);
    bool chceckDateWord(vector <string> date);

};


#endif // FILE_H





