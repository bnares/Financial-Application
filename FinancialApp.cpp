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
}
