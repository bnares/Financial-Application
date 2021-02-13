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


vector <Expense> LoggedUserManager :: sortExpenseByDate()
{
    vector <Expense> copyOfExpenses = expenses;
    sort(copyOfExpenses.begin(), copyOfExpenses.end());
    return copyOfExpenses;

}



vector <Income> LoggedUserManager :: sortIncomesByDate()
{
    vector <Income> copyOfIncomes = incomes;
    sort(copyOfIncomes.begin(), copyOfIncomes.end());
    return copyOfIncomes;
}

void LoggedUserManager :: printSortedExpenses()
{
    for(int i =0; i<expenses.size(); i++)
    {
        cout<<expenses[i].getDate()<<endl;
    }
}

