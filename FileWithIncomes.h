#ifndef FILEWITHINCOMES_H

#define FILEWITHINCOMES_H
#include "File.h"
#include "Income.h"
#include <iostream>
#include "Markup.h"
using namespace std;



class IncomesFile : public File

{
    vector <Income> incomes;



public:
    void readFromFileData(vector <Income> &incomes);




    IncomesFile(string fileName, int userId)
    : File(fileName, userId)
    {
        readFromFileData(incomes);


    };

    vector <Income> getIncomes();

};


#endif // FILEWITHINCOMES_H
