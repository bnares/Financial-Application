#include <iostream>
#include "LoggedUserManager.h"

using namespace std;

void LoggedUserManager :: addExpenseToFile()
{

    expensesFile.addToFile();

}



void LoggedUserManager :: addIncomeToFile()
{
    incomesFile.addToFile();
}


int LoggedUserManager :: getDate()
{

    int dwa = expensesFile.expenseSize();
    int rozmiar = expenses.size();
    return dwa;
}

