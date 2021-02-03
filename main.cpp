#include <iostream>
#include "Interface.h"
#include "FinancialApp.h"

using namespace std;

int main()
{
    Menu menu;
    FinancialApp financialApp("Uzytkownicy.xml", "Dochody.xml", "Wydatki.xml");
    int controlValue = financialApp.userMenager.getLastUserId();



    while(true)
    {
        if(controlValue == 1)

        {


            char choice = menu.openingMenu();
            switch(choice)
            {

            case'1':
                {
                    financialApp.registerUser();
                    break;
                }
            case '2':
                {
                    financialApp.signIn();
                    controlValue = financialApp.userMenager.getLastUserId();
                    break;
                }
            case '3':
                {
                    exit(0);
                }
            }
        }

    }

    return 0;
}
