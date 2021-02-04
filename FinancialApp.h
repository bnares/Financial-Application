#ifndef FINANCIALAPP_H
#define FINANCIALAPP_H

#include <iostream>
#include "UserMenager.h"
#include "LoggedUserManager.h"

using namespace std;


class FinancialApp
{
        int idLoggedUser;


        public:
        UserMenager userMenager;
        const string NAZWA_PLIKU_DOCHODY;
        const string NAZWA_PLIKU_WYDATKI;
        LoggedUserManager *loggedUserManager;
        void setIdLoggedUser(int id);

        FinancialApp(string nazwaPlikuUzytkownicy, string nazwaPlikuDochody, string nazwaPlikuWydatki)
        : userMenager(nazwaPlikuUzytkownicy), NAZWA_PLIKU_DOCHODY(nazwaPlikuDochody), NAZWA_PLIKU_WYDATKI(nazwaPlikuWydatki)
        {

            loggedUserManager = NULL;
            idLoggedUser = userMenager.getLastUserId();

        };


        ~FinancialApp()
        {
            delete loggedUserManager;
            loggedUserManager = NULL;

        };

        int getLastUserID();
        void registerUser();
        void signIn();


};






#endif
