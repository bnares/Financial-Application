#include <iostream>
#include "Interface.h"

using namespace std;


char Menu::openingMenu()
{
    char wybor;
    system("cls");
    cout<<"MENU GLOWNE"<<endl;
    cout<<"-----------"<<endl;
    cout<<"1-Rejestracja"<<endl;
    cout<<"2-Logowanie"<<endl;
    cout<<"3-Zakoncz"<<endl;
    cout<<"Twoj wybor: ";

    wybor = AuxiliaryMethods::getChar();

    return wybor;


}
