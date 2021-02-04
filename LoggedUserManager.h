#ifndef LOGGEDUSERMANAGER_H
#define LOGGEDUSERMANAGER_H

#include <iostream>

using namespace std;

class LoggedUserManager
{
    int const ID_NUMBER_LOGGED_USER;
    string const EXPENSESS_FILE_NAME;
    string const INCOME_FILE_NAME;
public:
    LoggedUserManager(int idLoggedUser, string expensessFileName, string incomeFileName): ID_NUMBER_LOGGED_USER(idLoggedUser), EXPENSESS_FILE_NAME(expensessFileName), INCOME_FILE_NAME(incomeFileName)
    {

    };
};





#endif // LOGGEDUSERMANAGER_H
