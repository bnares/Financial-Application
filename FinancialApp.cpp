#include "FinancialApp.h"

#include <iostream>

using namespace std;

FinancialApp:: FinancialApp(string nazwaPlikuUzytkownicy, string nazwaPlikuDochody, string nazwaPlikuWydatki)
: userMenager(nazwaPlikuUzytkownicy)
{
    ;
}




void FinancialApp:: registerUser()
{
    userMenager.userRegister();
}


void FinancialApp :: signIn()
{
    userMenager.signIn();
}
