
#include "LoggedUserManager.h"



void LoggedUserManager::addExpenseToFile()
{

    expensesFile.addToFile();
    expenses.clear();
    expensesFile.readFromFileData(expenses);
    expenses = sortExpenseByDate();

}



void LoggedUserManager::addIncomeToFile()
{
    incomesFile.addToFile();
    incomes.clear();
    incomesFile.readFromFileData(incomes);
    incomes = sortIncomesByDate();
}


int LoggedUserManager::getDate()
{

    int dwa = expensesFile.expenseSize();
    int rozmiar = expenses.size();
    return dwa;
}


vector <Expense> LoggedUserManager::sortExpenseByDate()
{
    vector <Expense> copyOfExpenses = expenses;
    sort(copyOfExpenses.begin(), copyOfExpenses.end());
    return copyOfExpenses;

}



vector <Income> LoggedUserManager::sortIncomesByDate()
{
    vector <Income> copyOfIncomes = incomes;
    sort(copyOfIncomes.begin(), copyOfIncomes.end());
    return copyOfIncomes;
}

void LoggedUserManager::printSortedExpenses()
{
    for(int i =0; i<expenses.size(); i++)
    {
        cout<<expenses[i].getDate()<<endl;
    }
}

void LoggedUserManager::printSortedIncomes()
{
    for(int i =0; i<incomes.size(); i++)
    {
        cout<<incomes[i].getDate()<<endl;
    }
}


void LoggedUserManager::printCurrentMonthResult()
{
    Date currentDate;
    int dateNumber = currentDate.getTodayDateAsNumber();
    string dateString = AuxiliaryMethods::convertNumberToString(dateNumber);
    string lastTwoNumbersFromCurrentDate= "";
    int currentDateStringLength = dateString.length();
    for(int i = currentDateStringLength-2; i<currentDateStringLength; i++)
    {
        if(isdigit(dateString[i]))
        {
            lastTwoNumbersFromCurrentDate+=dateString[i];

        }
        else
        {
            cout<<"sth went wrong, sorry with the date, sorry..."<<endl;
            Sleep(1000);
            break;
        }
    }
    int getLastTwoDatesNumbers = AuxiliaryMethods::convertStringToNUmber(lastTwoNumbersFromCurrentDate);
    int lowerBoundryDateNumber = dateNumber - getLastTwoDatesNumbers+1;
    float sumExpenses =0.0;
    float sumIncomes = 0.0;
    int occurrences = 0;
    cout<<"INCOMES:"<<endl;
    for(int i =0; i< incomes.size(); i++)
    {
        if(lowerBoundryDateNumber <= incomes[i].getDate() && incomes[i].getDate() <= dateNumber)
        {
            cout<<"Incom: +"<<incomes[i].getAmountOfMoney()<<" Description: "<<incomes[i].getDescription()<<" Date: "<<incomes[i].getDate()<<endl;
            sumIncomes+=incomes[i].getAmountOfMoney();
            occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"no incomes in this period of time"<<endl;
    }
    occurrences = 0;

    cout<<endl;
    cout<<"EXPENSES:"<<endl;
    for(int i =0; i<expenses.size(); i++)
    {
        if(lowerBoundryDateNumber <= expenses[i].getDate() && expenses[i].getDate() <= dateNumber)
        {
           cout<<"Expense: -"<<expenses[i].getAmountOfMoney()<<" Description: "<<expenses[i].getDescription()<<" Date: "<<expenses[i].getDate()<<endl;
           sumExpenses+=expenses[i].getAmountOfMoney();
           occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"no expenses in this period of time"<<endl;
    }
    cout<<endl;
    float result = sumIncomes - sumExpenses;
    if(result>=0)
    {
        cout<<"so far You have earned: "<<result<<endl;
    }
    else
    {
        cout<<"so far You have lost: "<<result<<endl;
    }

}







void LoggedUserManager::printPreviousMonthResult()
{
    Date today;
    int lowerBoundryDateNumber;
    int upperBoundryDateNumber;
    int todayDateAsNumber = today.getTodayDateAsNumber();
    string todayDateAsString = AuxiliaryMethods::convertNumberToString(todayDateAsNumber);
    int lengthOfStringDate = todayDateAsString.length();
    string yerarString="";
    string monthString="";
    string dayString="";

    for(int i =0; i<lengthOfStringDate; i++)
    {
        if(i<4)
        {
            yerarString+=todayDateAsString[i];
        }
        if(i>=4 && i<lengthOfStringDate-2)
        {
            monthString+=todayDateAsString[i];
        }
        if(i>=lengthOfStringDate-2 && i<lengthOfStringDate)
        {
            dayString+=todayDateAsString[i];
        }
    }
    int yearNumber = AuxiliaryMethods::convertStringToNUmber(yerarString);
    int monthNumber = AuxiliaryMethods::convertStringToNUmber(monthString)-1;
    int daysNumber;

    if(monthNumber==2)
    {
        if(yearNumber%400 ==0 || (yearNumber %4==0 && yearNumber %100 !=0))
        {
            daysNumber = 29;
        }
        else
        {
            daysNumber = 28;
        }
    }

    if(monthNumber == 1 || monthNumber == 3 || monthNumber == 5 || monthNumber==7 || monthNumber==8 || monthNumber == 10 || monthNumber ==12)
    {
        daysNumber =31;
    }
    else
    {
        daysNumber = 30;
    }

    if(monthNumber ==0)
    {
        monthNumber =12;
        daysNumber =31;
        yearNumber = yearNumber-1;
    }


    if(monthNumber<10)
    {
        monthString = "0"+AuxiliaryMethods::convertNumberToString(monthNumber);
    }
    else
    {
        monthString = AuxiliaryMethods::convertNumberToString(monthNumber);
    }

    if(daysNumber<10)
    {
        dayString = "0"+AuxiliaryMethods::convertNumberToString(daysNumber);
    }
    else
    {
        dayString = AuxiliaryMethods::convertNumberToString(daysNumber);
    }

    yerarString = AuxiliaryMethods::convertNumberToString(yearNumber);

    upperBoundryDateNumber = AuxiliaryMethods::convertStringToNUmber(yerarString+monthString+dayString);
    lowerBoundryDateNumber = AuxiliaryMethods::convertStringToNUmber(yerarString+monthString+"01");

    float sumExpenses =0;
    float sumIncomes = 0;
    int occurrences = 0;
    cout<<"INCOMES"<<endl;
    for(int i =0; i<incomes.size(); i++)
    {
        if(incomes[i].getDate()>=lowerBoundryDateNumber && incomes[i].getDate()<=upperBoundryDateNumber)
        {
            cout<<"Incom: +"<<incomes.at(i).getAmountOfMoney()<<" Description: "<<incomes.at(i).getDescription()<<" Date: "<<incomes.at(i).getDate()<<endl;

            sumIncomes+=incomes.at(i).getAmountOfMoney();
            occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"No income in last month"<<endl;
    }
    occurrences=0;
    cout<<endl;
    cout<<"EXPENSES"<<endl;
    for(int i =0; i<expenses.size(); i++)
    {
        if(expenses[i].getDate()>=lowerBoundryDateNumber && expenses[i].getDate()<=upperBoundryDateNumber)
        {
            cout<<"Expens: -"<<expenses.at(i).getAmountOfMoney()<<" Description: "<<expenses.at(i).getDescription()<<" Date"<<expenses.at(i).getDate()<<endl;

            sumExpenses+=expenses.at(i).getAmountOfMoney();
            occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"No expenses in last month"<<endl;
    }

    cout<<endl;
    float result = sumIncomes - sumExpenses;
    if(result>=0)
    {
        cout<<"so far You have earned: "<<result<<endl;
    }
    else
    {
        cout<<"so far You have lost: "<<result<<endl;
    }


}


void LoggedUserManager::selectPeriodOfTime()
{
   int year;
   int month;
   int day;
   cout<<"Select first date"<<endl;
   cout<<"Date as yyyy-mm-dd: ";
   string firstDate = AuxiliaryMethods::getText();
   vector <string> stringDateVector = AuxiliaryMethods::createVectorFromDateWords(firstDate);
   bool chceckDate = incomesFile.chceckDateWord(stringDateVector);
   while(chceckDate == false)
   {
       cout<<"Wrong date!"<<endl;
       cout<<"Date as yyyy-mm-dd: ";
       firstDate = AuxiliaryMethods::getText();
       stringDateVector.clear();
       stringDateVector = AuxiliaryMethods::createVectorFromDateWords(firstDate);
       chceckDate = incomesFile.chceckDateWord(stringDateVector);
   }
   year = AuxiliaryMethods::convertStringToNUmber(stringDateVector[0]);
   month = AuxiliaryMethods::convertStringToNUmber(stringDateVector[1]);
   day = AuxiliaryMethods::convertStringToNUmber(stringDateVector[2]);

   Date lowerDate(day, month, year);

   cout<<"Select second date"<<endl;
   cout<<"Date as yyyy-mm-dd: ";
   firstDate = AuxiliaryMethods::getText();
   stringDateVector = AuxiliaryMethods::createVectorFromDateWords(firstDate);
   chceckDate = incomesFile.chceckDateWord(stringDateVector);
   while(chceckDate == false)
   {
       cout<<"Wrong date!"<<endl;
       cout<<"Date as yyyy-mm-dd: ";
       firstDate = AuxiliaryMethods::getText();
       stringDateVector.clear();
       stringDateVector = AuxiliaryMethods::createVectorFromDateWords(firstDate);
       chceckDate = incomesFile.chceckDateWord(stringDateVector);
   }

   year = AuxiliaryMethods::convertStringToNUmber(stringDateVector[0]);
   month = AuxiliaryMethods::convertStringToNUmber(stringDateVector[1]);
   day = AuxiliaryMethods::convertStringToNUmber(stringDateVector[2]);


   Date upperDate(day, month, year);

   int firstDateNumber = lowerDate.getDateAsNumber();
   int secondDateNumber = upperDate.getDateAsNumber();

   float sumExpenses =0;
   float sumIncomes = 0;
   int occurrences = 0;


   cout<<"INCOMES:"<<endl;
   for(int i =0; i<incomes.size(); i++)
   {
       if(incomes.at(i).getDate()>= firstDateNumber && incomes.at(i).getDate()<=secondDateNumber)
       {
           cout<<"Incom: +"<<incomes.at(i).getAmountOfMoney()<<" Description: "<<incomes.at(i).getDescription()<<" Date: "<<incomes.at(i).getDate()<<endl;

            sumIncomes+=incomes.at(i).getAmountOfMoney();
            occurrences++;
       }
   }

   if(occurrences==0)
   {
       cout<<"No income in this period of time"<<endl;
   }
   occurrences =0;

   cout<<"EXPENSES"<<endl;
    for(int i =0; i<expenses.size(); i++)
    {
        if(expenses[i].getDate()>=firstDateNumber && expenses[i].getDate()<=secondDateNumber)
        {
            cout<<"Expens: -"<<expenses.at(i).getAmountOfMoney()<<" Description: "<<expenses.at(i).getDescription()<<" Date: "<<expenses.at(i).getDate()<<endl;

            sumExpenses+=expenses.at(i).getAmountOfMoney();
            occurrences++;
        }
    }
    if(occurrences==0)
    {
        cout<<"No expenses in selected period of time"<<endl;
    }

    cout<<endl;
    float result = sumIncomes - sumExpenses;
    if(result>=0)
    {
        cout<<"so far You have earned: "<<result<<endl;
    }
    else
    {
        cout<<"so far You have lost: "<<result<<endl;
    }



}










