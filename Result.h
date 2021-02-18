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
    float amountOfMoney;
public:
    int getIdUser();
    int getDate();
    float getAmountOfMoney();
    string getDescription();

    void setIdUser(int newId);
    void setDate(int newDate);
    void setDescription(string newDescription);
    void setAmountOfMoney(float money);
    bool operator < (Result &a)
    {
        return this ->getDate()<a.getDate();
    };
};


#endif // RESULT_H
