#ifndef USERSFILES_H

#define USERSFILES_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFile
{
    const string USERS_FILE_NAME;
    int lastUserId;
    CMarkup xml;
    int findLastUserId();
    void addUserToFile();
    void setLastUserId(int numberToSet);


public:
    UserFile(string usersFileName);
    int getLastUserId();

    void userRegister();
    int signIn();

};






#endif // USERSFILES_H
