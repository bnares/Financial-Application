#ifndef FINANCIALAPP_H
#define FINANCIALAPP_H

#include <iostream>
#include "UserMenager.h"

using namespace std;


class FinancialApp
{
    public:
        UserMenager userMenager;
        FinancialApp(string nazwaPlikuUzytkownicy, string nazwaPlikuDochody, string nazwaPlikuWydatki);
        void registerUser();
        void signIn();

};






#endif
