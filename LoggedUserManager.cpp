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

void LoggedUserManager :: printSortedIncomes()
{
    for(int i =0; i<incomes.size(); i++)
    {
        cout<<incomes[i].getDate()<<endl;
    }
}


void LoggedUserManager :: printCurrentMonthResult()
{
    Date currentDate;
    int dateNumber = currentDate.getTodayDateAsNumber();
    string dateString = AuxiliaryMethods::convertNumberToString(dateNumber);
    string lastTwoNumbersFromCurrentDate= "";
    int currentDateStringLength = dateString.length();
    for(int i = currentDateStringLength-2; i<currentDateStringLength; i++)
    {
        if(isdigit(dateString[i]))
        {
            lastTwoNumbersFromCurrentDate+=dateString[i];

        }
        else
        {
            cout<<"sth went wrong sorry with the dates, sorry..."<<endl;
            Sleep(1000);
            break;
        }
    }
    int getLastTwoDatesNumbers = AuxiliaryMethods::convertStringToNUmber(lastTwoNumbersFromCurrentDate);
    int lowerBoundryDateNumber = dateNumber - getLastTwoDatesNumbers+1;
    int sumExpenses =0;
    int sumIncomes = 0;
    int occurrences = 0;
    cout<<"INCOMES:"<<endl;
    for(int i =0; i< incomes.size(); i++)
    {
        if(lowerBoundryDateNumber <= incomes[i].getDate() && incomes[i].getDate() <= dateNumber)
        {
            cout<<"Incom: +"<<incomes[i].getAmountOfMoney()<<" Description: "<<incomes[i].getDescription()<<endl;
            sumIncomes+=incomes[i].getAmountOfMoney();
            occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"no incomes in this period of time"<<endl;
    }
    occurrences = 0;

    cout<<endl;
    cout<<"EXPENSES:"<<endl;
    for(int i =0; i<expenses.size(); i++)
    {
        if(lowerBoundryDateNumber <= expenses[i].getDate() && expenses[i].getDate() <= dateNumber)
        {
           cout<<"Expense: -"<<expenses[i].getAmountOfMoney()<<" Description: "<<expenses[i].getDescription()<<endl;
           sumExpenses+=expenses[i].getAmountOfMoney();
           occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"no expenses in this period of time"<<endl;
    }
    cout<<endl;
    float result = sumIncomes - sumExpenses;
    if(result>=0)
    {
        cout<<"so far You have earned: "<<result<<endl;
    }
    else
    {
        cout<<"so far You have lost: "<<result<<endl;
    }

}

