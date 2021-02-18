
#include "Interface.h"



char Menu::openingMenu()
{
    char choice;
    system("cls");
    cout<<" MAIN MENU "<<endl;
    cout<<"-----------"<<endl;
    cout<<"1-Register"<<endl;
    cout<<"2-Sign in"<<endl;
    cout<<"3-Exit"<<endl;
    cout<<"User choice: ";

    choice = AuxiliaryMethods::getChar();
    return choice;
}


char Menu::loggedInMenu()
{
    char choice;
    system("cls");
    cout<<"   USER MENU    "<<endl;
    cout<<"----------------"<<endl;
    cout<<"1-Add income"<<endl;
    cout<<"2-Add expense"<<endl;
    cout<<"3-Current mont result"<<endl;
    cout<<"4-Last month result"<<endl;
    cout<<"5-Selected period result"<<endl;
    cout<<"6-Change password"<<endl;
    cout<<"7-Sign out"<<endl;
    choice = AuxiliaryMethods ::getChar();
    return choice;

}
