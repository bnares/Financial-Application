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
    int idOfLoggedUser;
    int lastUserId;
    CMarkup xml;
    int findLastUserId();
    void addUserToFile();
    void setLastUserId(int numberToSet);
    void setIdOfLoggedUser(int idToSet);


public:
    UserFile(string usersFileName);
    int getLastUserId();
    int getIdLoggedUser();

    void userRegister();
    void signIn();

};






#endif // USERSFILES_H
