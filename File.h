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
    vector <string> createVectorFromDateWords(string date);
    string modifyFileName(string fileName);
    bool chceckDateWord(vector <string> date);
public:
    File(string fileName, int userId)
    : FILE_NAME(fileName), idNumberOfUser(userId)
    {
        idNumberOfTheLastActivity = findIdNumberOfTheLastActivity();
    };

    void addToFile();
    int getIdNumberOfTheLastActivity();
};










#endif // FILE_H





