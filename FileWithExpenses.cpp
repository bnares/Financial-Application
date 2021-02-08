#include "FileWithExpenses.h"
#include <iostream>
#include "Expense.h"


using namespace std;







void ExpensesFile :: readFromFileData(vector <Expense> &expenses)
{
    cout<<"FILE_NAME in redFromFileData: "<<FILE_NAME<<endl;

    //int lengthOfTitle = FILE_NAME.length()-4;
    //string mainTitleOfFile = FILE_NAME.erase(lengthOfTitle,4);
    string mainTitleOfFile = FILE_NAME;
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem(mainTitleOfFile))
    {

        Expense expense;
        xml.IntoElem();
        xml.FindElem("IdOfActivity");
        string activityId = xml.GetData();
        int activityIdNumber = AuxiliaryMethods ::convertStringToNUmber(activityId);
        xml.FindElem("UserId");
        string id = xml.GetData();
        int userId = AuxiliaryMethods ::convertStringToNUmber(id);
        if(userId == idNumberOfUser)
        {


            xml.FindElem("Date");
            string findDate = xml.GetData();
            int numberDate = AuxiliaryMethods::convertStringToNUmber(findDate);
            xml.FindElem("Descritpion");
            string description = xml.GetData();
            xml.FindElem("Amount");
            string cash = xml.GetData();
            int money = AuxiliaryMethods::convertStringToNUmber(cash);
            expense.setExpenseId(activityIdNumber);
            expense.setIdUser(userId);
            expense.setDate(numberDate);
            expense.setDescription(description);
            expense.setAmountOfMoney(money);
            expenses.push_back(expense);
            xml.OutOfElem();
        }
        else
        {
            xml.OutOfElem();
        }

    }


}


vector <Expense>  ExpensesFile :: getExpenses()
{
    return expenses;
}
