#ifndef FILEWITHEXPENSES_H

#define FILEWITHEXPENSES_H
#include "File.h"
#include "Expense.h"
#include <iostream>
#include "Markup.h"
using namespace std;



class ExpensesFile : public File

{
    vector <Expense> expenses;



public:
    void readFromFileData(vector <Expense> &expenses);




    ExpensesFile(string fileName, int userId)
    : File(fileName, userId)
    {
        readFromFileData(expenses);


    };

    vector <Expense> getExpenses();
    int expenseSize();


};


#endif // FILEWITHEXPENSES_H
