#ifndef RESULT_H

#define RESULT_H
#include <iostream>

using namespace std;


class Result
{
    protected:
    int idUser;
    int date;
    string desciptonOfActivity;
    int amountOfMoney;
public:
    int getIdUser();
    int getDate();
    int getAmountOfMoney();
    string getDescription();

    void setIdUser(int newId);
    void setDate(int newDate);
    void setDescription(string newDescription);
    void setAmountOfMoney(int money);
};


#endif // RESULT_H
