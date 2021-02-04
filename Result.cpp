#include <iostream>
#include "Result.h"


using namespace std;






int Result :: getIdUser()
{
        return idUser;
}


int Result :: getDate()
{
    return date;
}

int Result :: getAmountOfMoney()
{
    return amountOfMoney;
}


string Result :: getDescription()
{
    return desciptonOfActivity;
}


void Result :: setIdUser(int newId)
{
    idUser = newId;
}
void Result :: setDate(int newDate)
{
    date = newDate;
}

void Result :: setDescription(string newDescription)
{
    desciptonOfActivity = newDescription;
}


void Result :: setAmountOfMoney(int money)
{
    amountOfMoney = money;
}
