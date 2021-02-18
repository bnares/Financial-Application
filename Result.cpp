
#include "Result.h"


int Result::getIdUser()
{
        return idUser;
}


int Result::getDate()
{
    return date;
}

float Result::getAmountOfMoney()
{
    return amountOfMoney;
}


string Result::getDescription()
{
    return desciptonOfActivity;
}


void Result::setIdUser(int newId)
{
    idUser = newId;
}
void Result::setDate(int newDate)
{
    date = newDate;
}

void Result::setDescription(string newDescription)
{
    desciptonOfActivity = newDescription;
}


void Result::setAmountOfMoney(float money)
{
    amountOfMoney = money;
}
