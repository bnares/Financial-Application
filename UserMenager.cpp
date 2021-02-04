#include <iostream>
#include "UserMenager.h"


using namespace std;

UserMenager :: UserMenager(string userFileName)
: FILE_NAME_WITH_USERS(userFileName), userFile(FILE_NAME_WITH_USERS)
{
    lastUserId = getLastUserId();
    idOfLoggedUser = getIdOfLoggedUser();
}

void UserMenager :: userRegister()
{
    userFile.userRegister();

}


void UserMenager :: signIn()
{
    userFile.signIn();

}


int UserMenager :: getLastUserId()

{
    return userFile.getLastUserId();
}


int UserMenager :: getIdOfLoggedUser()
{
    return userFile.getIdLoggedUser();
}
