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
                    financialApp.AddIncome();
                    break;
                }
            case '2':
                {

                    financialApp.AddExpense();
                    break;
                }
            case '3':
                {
                    financialApp.printMonthlyResult();

                    system("pause");
                    break;
                }
            case'4':
                {
                    financialApp.printLastMonthResult();
                    system("pause");
                    break;
                }
            case '5':
                {
                    financialApp.printResultOfSelectedPeriodOfTime();
                    system("pause");
                    break;
                }
            case '6':
                {
                    cout<<"przed"<<endl;
                    financialApp.changePassword();
                    cout<<"po"<<endl;
                    break;
                }
            }
        }

    }

    return 0;
}
