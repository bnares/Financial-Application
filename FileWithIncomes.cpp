#include "FileWithIncomes.h"




void IncomesFile :: readFromFileData(vector <Income> &incomes)
{


    string mainTitleOfFile = modifyFileName(FILE_NAME);

    if(xml.Load(FILE_NAME.c_str()))

    {

        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem(mainTitleOfFile))
        {

            Income income;
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
                vector <string> dateVector = createVectorFromDateWords(findDate);
                string stringNumber = createStringNumberFromStringVector(dateVector);
                int numberDate = AuxiliaryMethods::convertStringToNUmber(stringNumber);
                xml.FindElem("Descritpion");
                string description = xml.GetData();
                xml.FindElem("Amount");
                string cash = xml.GetData();
                float money = AuxiliaryMethods::convertStringToFloatNumber(cash);
                income.setIncomeId(activityIdNumber);
                income.setIdUser(userId);
                income.setDate(numberDate);
                income.setDescription(description);
                income.setAmountOfMoney(money);
                incomes.push_back(income);
                xml.OutOfElem();
            }
            else
            {
                xml.OutOfElem();
            }

        }

    }


}


vector <Income>  IncomesFile :: getIncomes()
{
    return incomes;
}
