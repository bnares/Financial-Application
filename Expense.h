#ifndef EXPENSE_H

#define EXPENSE_H

#include <iostream>
#include <vector>
#include "Result.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"


using namespace std;


class Expense : public Result
{
    int expenseId;
public:
    int getExpenseId();
    void setExpenseId(int newExpenseId);

};



#endif // EXPENSE_H
