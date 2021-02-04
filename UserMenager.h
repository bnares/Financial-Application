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
    vector <User> users;
    UserFile userFile;

public:

    UserMenager(string userFileName);
    void userRegister();
    void signIn();
    int getLastUserId();
};



#endif // USERMENAGER
