#ifndef INCOME_H

#define INCOME_H

#include <iostream>
#include <vector>
#include "Result.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"


class Income : public Result
{
    int incomeId;
public:
    int getIncomeId();
    void setIncomeId(int newIncomeId);
};

using namespace std;







#endif // INCOME_H
