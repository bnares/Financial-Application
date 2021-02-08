#ifndef INCOME_H

#define INCOME_H

#include <iostream>
#include <vector>
#include "Result.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
using namespace std;


class Income : public Result
{
    int incomeId;
public:
    int getIncomeId();
    void setIncomeId(int newIncomeId);
};









#endif // INCOME_H
