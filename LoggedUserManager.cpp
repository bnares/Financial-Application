#include <iostream>
#include "LoggedUserManager.h"

using namespace std;

void LoggedUserManager :: addToFile()
{
    cout<<"Message to expensesFile.addToFile()"<<endl;
    system("pause");
    expensesFile.addToFile();
}
