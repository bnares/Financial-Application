#include <iostream>
#include "Interface.h"

using namespace std;


char Menu::openingMenu()
{
    char choice;
    system("cls");
    cout<<"MENU GLOWNE"<<endl;
    cout<<"-----------"<<endl;
    cout<<"1-Rejestracja"<<endl;
    cout<<"2-Logowanie"<<endl;
    cout<<"3-Zakoncz"<<endl;
    cout<<"Twoj wybor: ";

    choice = AuxiliaryMethods::getChar();

    return choice;



}


char Menu :: loggedInMenu()
{
    char choice;
    system("cls");
    cout<<"MENU UZYTKOWNIKA"<<endl;
    cout<<"----------------"<<endl;
    cout<<"1-Add income"<<endl;
    cout<<"2-Add expense"<<endl;
    cout<<"3-Current mont result"<<endl;
    cout<<"4-Last month result"<<endl;
    cout<<"5-Selected period result"<<endl;
    cout<<"6-Change password"<<endl;
    choice = AuxiliaryMethods ::getChar();
    return choice;

}
