#ifndef LOGGEDUSERMANAGER_H
#define LOGGEDUSERMANAGER_H

#include <iostream>
#include "Income.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include <vector>
#include <windows.h>

using namespace std;

class LoggedUserManager
{
    int const ID_NUMBER_LOGGED_USER;
    string const EXPENSESS_FILE_NAME;
    string const INCOME_FILE_NAME;
    vector <Income> incomes;
    vector <Expense> expenses;
    ExpensesFile expensesFile;
    IncomesFile incomesFile;

public:
    LoggedUserManager(int idLoggedUser, string expensessFileName, string incomeFileName)
    : ID_NUMBER_LOGGED_USER(idLoggedUser), EXPENSESS_FILE_NAME(expensessFileName), INCOME_FILE_NAME(incomeFileName), expensesFile(expensessFileName, idLoggedUser), incomesFile(incomeFileName, idLoggedUser)
    {
        expenses = expensesFile.getExpenses();
        expenses = sortExpenseByDate();
        incomes = incomesFile.getIncomes();
        incomes = sortIncomesByDate();

    };

    void addExpenseToFile();
    void addIncomeToFile();
    int getDate();
    vector <Expense> sortExpenseByDate();
    vector <Income> sortIncomesByDate();
    void printCurrentMonthResult();
    void printPreviousMonthResult();

    //testowe
    void printSortedExpenses();
    void printSortedIncomes();
};











#endif LOGGEDUSERMANAGER_H
