#ifndef USERMENAGER_H

#define USERMENAGER_H


#include <iostream>
#include <vector>
#include "AuxiliaryMethods.h"
#include "User.h"
#include "UsersFiles.h"


using namespace std;

class UserMenager
{
    const string FILE_NAME_WITH_USERS;
    int lastUserId;
    int idOfLoggedUser;
    vector <User> users;
    UserFile userFile;

public:

    UserMenager(string userFileName);
    void userRegister();
    int signIn();
    int getLastUserId();
    int getIdOfLoggedUser();
};



#endif // USERMENAGER
