#include "FileWithExpenses.h"












void ExpensesFile :: readFromFileData(vector <Expense> &expenses)
{


    //int lengthOfTitle = FILE_NAME.length()-4;
    //string mainTitleOfFile = FILE_NAME.erase(lengthOfTitle,4);
    string mainTitleOfFile = modifyFileName(FILE_NAME);
    if(xml.Load(FILE_NAME.c_str()))
    {

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
            //TUTAJ ZAMIENIAJ DATE NA CIAG LICZB!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            vector <string> dateVector = createVectorFromDateWords(findDate);
            string stringNumber = createStringNumberFromStringVector(dateVector);
            int numberDate = AuxiliaryMethods::convertStringToNUmber(stringNumber);
            xml.FindElem("Descritpion");
            string description = xml.GetData();
            xml.FindElem("Amount");
            string cash = xml.GetData();

            float money = AuxiliaryMethods::convertStringToFloatNumber(cash);
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


}


vector <Expense>  ExpensesFile :: getExpenses()
{

    vector <Expense> data;
    for(int i =0; i<expenses.size(); i++)
    {
        Expense fileData;
        fileData.setExpenseId(expenses[i].getExpenseId());
        fileData.setIdUser(expenses[i].getIdUser());
        fileData.setDate(expenses[i].getDate());
        fileData.setDescription(expenses[i].getDescription());
        fileData.setAmountOfMoney(expenses[i].getAmountOfMoney());
        data.push_back(fileData);
        cout<<"Info: "<<fileData.getAmountOfMoney()<<endl;
    }
    return data;
}



int ExpensesFile :: expenseSize()
{
    int rozmiar = expenses.size();
    cout<<"Size after constructor: "<<rozmiar<<endl;
    return rozmiar;
}



