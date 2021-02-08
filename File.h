#ifndef FILE_H


#define FILE_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"


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





