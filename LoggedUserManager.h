#ifndef LOGGEDUSERMANAGER_H
#define LOGGEDUSERMANAGER_H

#include <iostream>
#include "Income.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include <vector>

using namespace std;

class LoggedUserManager
{
    int const ID_NUMBER_LOGGED_USER;
    string const EXPENSESS_FILE_NAME;
    string const INCOME_FILE_NAME;
    vector <Income> income;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

public:
    LoggedUserManager(int idLoggedUser, string expensessFileName, string incomeFileName)
    : ID_NUMBER_LOGGED_USER(idLoggedUser), EXPENSESS_FILE_NAME(expensessFileName), INCOME_FILE_NAME(incomeFileName), expensesFile(expensessFileName, idLoggedUser)
    {
        expenses = expensesFile.getExpenses();
    };

    void addToFile();
};





#endif LOGGEDUSERMANAGER_H
