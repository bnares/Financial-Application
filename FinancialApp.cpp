#include "FinancialApp.h"

#include <iostream>

using namespace std;




void FinancialApp:: registerUser()
{
    userMenager.userRegister();
}


void FinancialApp :: signIn()
{
    userMenager.signIn();
    if(userMenager.getLastUserId()!=1)
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
