#include <iostream>
#include "Interface.h"
#include "FinancialApp.h"

using namespace std;

int main()
{
    cout<<"WOW"<<endl;
    Menu menu;
    cout<<"WOW"<<endl;
    FinancialApp financialApp("Uzytkownicy.xml", "Dochody.xml", "Wydatki.xml");
    cout<<"WOW"<<endl;
    int controlValue = financialApp.userMenager.getLastUserId();
    cout<<"control value: "<<controlValue<<endl;



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
        else
        {

        }

    }

    return 0;
}
