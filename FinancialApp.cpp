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
    cout<<"userMenager.getLastUserId(): "<<userMenager.getLastUserId()<<endl;
    system("pause");
    if(idOfLoggedUser!=0)
    {
        loggedUserManager = new LoggedUserManager(idOfLoggedUser, NAZWA_PLIKU_WYDATKI, NAZWA_PLIKU_DOCHODY);
        cout<<"idOfLoggedUser, NAZWA_WYDATKI, NAZWA_DOCHODY w FinancialApp SignIN()"<<idOfLoggedUser<<" "<<NAZWA_PLIKU_WYDATKI<<" "<<NAZWA_PLIKU_DOCHODY<<endl;
        system("pause");

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
    cout<<"message from FinancialApp to loggedUserManager -> addToFile()"<<endl;
    cout<<"idOfLoggedUser "<<idOfLoggedUser<<endl;
    cout<<"Nazwa pliku dochody i wydatki: "<<NAZWA_PLIKU_DOCHODY<<" "<<NAZWA_PLIKU_WYDATKI<<endl;
    system("pause");
    loggedUserManager -> addToFile();
}
