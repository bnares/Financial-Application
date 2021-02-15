#include <iostream>
#include "UsersFiles.h"


using namespace std;

UserFile :: UserFile(string usersFileName)
: USERS_FILE_NAME(usersFileName), lastUserId(findLastUserId())
{

}


void UserFile :: setIdOfLoggedUser(int idToSet)
{
    idOfLoggedUser = idToSet;

}


int UserFile :: getLastUserId()
{
    return lastUserId;
}

void UserFile :: setLastUserId(int numberToSet)
{
    lastUserId = numberToSet;
}


int UserFile :: findLastUserId()
{

    int idNumber =0;
    if(xml.Load(USERS_FILE_NAME.c_str()))
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("ID");
            string id = xml.GetData();
            xml.OutOfElem();
            idNumber = AuxiliaryMethods :: convertStringToNUmber(id);
        }

        return idNumber+1;
    }
    else
    {
        return 1;
    }

}

void  UserFile :: addUserToFile()
{
    string id, login= "", password="", name="", surname="";
    vector <string> data = {login, password, name, surname};


    for(vector <string>:: iterator itr = data.begin(); itr != data.end(); itr++)
    {
        string text="";
        cin.clear();
        cin.sync();
        cout<<"write sequentially login, password, name and surname, press enter each time ";
        getline(cin, text);
        *itr = text;
        cout<<"itr :"<<*itr<<endl;
        cout<<endl;
    }

    id = AuxiliaryMethods :: convertNumberToString(lastUserId);

    if(xml.Load(USERS_FILE_NAME.c_str()))
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("ID", id);
        xml.AddElem("Login", data[0]);
        xml.AddElem("Password", data[1]);
        xml.AddElem("Name", data[2]);
        xml.AddElem("Surname", data[3]);
        xml.Save(USERS_FILE_NAME.c_str());
    }
    else
    {
        xml.AddElem("Users");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("ID", id);
        xml.AddElem("Login", data[0]);
        xml.AddElem("Password", data[1]);
        xml.AddElem("Name", data[2]);
        xml.AddElem("Surname", data[3]);
        xml.Save(USERS_FILE_NAME.c_str());
    }
}



void UserFile :: userRegister()
{

    if(xml.Load(USERS_FILE_NAME.c_str()))
    {

        lastUserId = findLastUserId();
        addUserToFile();
    }

    else
    {

        lastUserId = findLastUserId();
        addUserToFile();
    }

}


int UserFile :: signIn()
{
    int occurances = 0;
    cout<<"Login: ";
    string login;
    login = AuxiliaryMethods :: getText();
    string password;
    cout<<"Password: ";
    password = AuxiliaryMethods :: getText();
    if(xml.Load(USERS_FILE_NAME.c_str()))
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("ID");
            string userId = xml.GetData();
            xml.FindElem("Login");
            string selectedUserLogin = xml.GetData();
            xml.FindElem("Password");
            string selectedUserPassword = xml.GetData();

            if(login == selectedUserLogin && password == selectedUserPassword)
            {
                cout<<"You have just signed in"<<endl;
                cout<<"WELCOME "<<selectedUserLogin<<endl;
                int userNumber = AuxiliaryMethods ::convertStringToNUmber(userId);
                system("pause");
                setIdOfLoggedUser(AuxiliaryMethods ::convertStringToNUmber(userId));
                occurances+=1;
                return AuxiliaryMethods ::convertStringToNUmber(userId);

            }
            xml.OutOfElem();
        }
    }
    if(occurances ==0)
    {
        cout<<"Nieprawidlowy login lub haslo"<<endl;
        system("pause");
        setIdOfLoggedUser(0);
        return 0;
    }
}



int UserFile :: getIdLoggedUser()
{

    return idOfLoggedUser;
}



CMarkup UserFile :: getCMarkup()
{
    return xml;
}
