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
                    controlValue = financialApp.getIdOfLoggedUser();
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
            char loggedInChoice;
            loggedInChoice = menu.loggedInMenu();
            switch(loggedInChoice)
            {
            case '1':
                {
                    break;
                }
            case '2':
                {

                    financialApp.AddExpense();
                    break;
                }
            }
        }

    }

    return 0;
}
