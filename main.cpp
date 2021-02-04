#include <iostream>
#include "Interface.h"
#include "FinancialApp.h"

using namespace std;

int main()
{

    Menu menu;
    FinancialApp financialApp("Uzytkownicy.xml", "Dochody.xml", "Wydatki.xml");
    int controlValue = 0;




    while(true)
    {
        if(controlValue == 0)

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
                    controlValue = financialApp.getLastUserID();
                    financialApp.setIdLoggedUser(controlValue);
                    break;
                }
            case '3':
                {
                    exit(0);
                }
            }
        }
        else
        {
            cout<<financialApp.getLastUserID()<<endl;
            cout<<"now you are in else"<<endl;
            char loggedInChoice;
            loggedInChoice = menu.loggedInMenu();
            switch(loggedInChoice)
            {
            case '1':
                {
                    ;
                }
            }
        }

    }

    return 0;
}
