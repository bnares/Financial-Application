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

