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


int UserMenager :: signIn()
{
    return userFile.signIn();

}


int UserMenager :: getLastUserId()

{
    return userFile.getLastUserId();
}


int UserMenager :: getIdOfLoggedUser()
{
    return userFile.getIdLoggedUser();
}


void UserMenager :: setIdOfLoggedUser(int number)
{
    idOfLoggedUser = number;
}


void UserMenager :: changePassword()
{
    setIdOfLoggedUser(getIdOfLoggedUser());
    if(xml.Load(FILE_NAME_WITH_USERS.c_str()))
    {


        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {

            xml.IntoElem();
            xml.FindElem("ID");
            string id =xml.GetData();
            int idNumberUser = AuxiliaryMethods::convertStringToNUmber(id);

            if(idNumberUser == idOfLoggedUser)
            {
                xml.FindElem("Password");
                xml.RemoveElem();
                cout<<"New Password: ";
                string noweHaslo;
                noweHaslo = AuxiliaryMethods::getText();
                xml.AddElem("Password", noweHaslo);
                cout<<"Password has been changed"<<endl;
                Sleep(1000);
                xml.Save(FILE_NAME_WITH_USERS.c_str());
            }
            xml.OutOfElem();
        }
    }
    else
    {
        cout<<"File do not exist"<<endl;
        Sleep(1500);
    }
}
