#include "FinancialApp.h"

#include <iostream>

using namespace std;




void FinancialApp:: registerUser()
{
    userMenager.userRegister();
}


void FinancialApp :: signIn()
{
    //userMenager.signIn();
    setIdLoggedUser(userMenager.signIn());
    if(idOfLoggedUser!=0)
    {
        loggedUserManager = new LoggedUserManager(idOfLoggedUser, NAZWA_PLIKU_WYDATKI, NAZWA_PLIKU_DOCHODY);

    }
}


int FinancialApp :: getLastUserID()
{
    return userMenager.getLastUserId();
}

void FinancialApp :: setIdLoggedUser(int id)
{
    idOfLoggedUser = id;
}



int FinancialApp :: getIdOfLoggedUser()
{
    return userMenager.getIdOfLoggedUser();
}


void FinancialApp :: AddExpense()
{

    loggedUserManager -> addExpenseToFile();
}

void FinancialApp :: AddIncome()
{
   loggedUserManager ->addIncomeToFile();
}


int FinancialApp :: getFirstDate()
{
    return loggedUserManager -> getDate();
}
