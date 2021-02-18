#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "User.h"
#include "UsersFiles.h"
#include <windows.h>
#include "Markup.h"


using namespace std;

class UserMenager
{
    const string FILE_NAME_WITH_USERS;
    int lastUserId;
    int idOfLoggedUser;
    vector <User> users;
    UserFile userFile;
    CMarkup xml;

public:
    UserMenager(string userFileName);
    void userRegister();
    int signIn();
    int getLastUserId();
    int getIdOfLoggedUser();
    void changePassword();
    void setIdOfLoggedUser(int number);
};



#endif // USERMENAGER
