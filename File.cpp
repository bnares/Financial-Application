#include "File.h"

#include <iostream>

using namespace std;

string File :: modifyFileName(string fileName)
{
    int lengthOfWord = fileName.length()-4;
    string word = fileName.erase(lengthOfWord,4);
    return word;
}



int File :: findIdNumberOfTheLastActivity()
{
    //int lengthOfTitle = FILE_NAME.length()-4;
    //string mainTitleOfFile = FILE_NAME.erase(lengthOfTitle,4);
    string mainTitleOfFile = modifyFileName(FILE_NAME);
    int number=0;
    if(xml.Load(FILE_NAME.c_str()))
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem(mainTitleOfFile))
        {
            xml.IntoElem();
            xml.FindElem("IdOfActivity");
            string activityId = xml.GetData();
            number = AuxiliaryMethods ::convertStringToNUmber(activityId);
            xml.OutOfElem();
        }
        return number;
    }
    else
    {
        return 0;
    }
}


int File :: getIdNumberOfTheLastActivity()
{
    return idNumberOfTheLastActivity;
}


void File :: setIdNumberOfTheLastActivity(int newLastNumberActivity)
{
    idNumberOfTheLastActivity = newLastNumberActivity;
}





void File :: addToFile()
{
    cout<<"FILE_NAME: "<<FILE_NAME<<endl;
    cout<<"IdNumberOfTheLastActivity: "<<idNumberOfTheLastActivity<<endl;
    cout<<"FILE - addToFile()"<<endl;
    //int lengthOfTitle = FILE_NAME.length()-4;
    //string mainTitleOfFile = FILE_NAME.erase(lengthOfTitle,4);
    string mainTitleOfFile = modifyFileName(FILE_NAME);
    string idActivity = "", idUser="", date="", descriptionOfActivity="", money="";
    idActivity = AuxiliaryMethods::convertNumberToString(idNumberOfTheLastActivity+1);
    idUser = AuxiliaryMethods::convertNumberToString(idNumberOfUser);
    vector <string> data = {date, descriptionOfActivity, money};
    for(vector <string>:: iterator it= data.begin(); it != data.end(); it++ )
    {
        cout<<"Write subsequently date as yyyy-mm-dd, descritpion, amount of money: "<<endl;
        *it = AuxiliaryMethods ::getText();
    }

    if(xml.Load(FILE_NAME.c_str()))
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem(mainTitleOfFile);
        xml.IntoElem();
        xml.AddElem("IdOfActivity", idActivity);
        xml.AddElem("UserId", idUser);
        xml.AddElem("Date", data[0]);
        xml.AddElem("Descritpion", data[1]);
        xml.AddElem("Amount", data[2]);
        xml.Save(FILE_NAME.c_str());
        setIdNumberOfTheLastActivity(idNumberOfTheLastActivity+1);

    }

    else
    {
        xml.AddElem("Activities");
        xml.IntoElem();
        xml.AddElem(mainTitleOfFile);
        xml.IntoElem();
        xml.AddElem("IdOfActivity", idActivity);
        xml.AddElem("UserId", idUser);
        xml.AddElem("Date", data[0]);
        xml.AddElem("Descritpion", data[1]);
        xml.AddElem("Amount", data[2]);
        xml.Save(FILE_NAME.c_str());
        setIdNumberOfTheLastActivity(idNumberOfTheLastActivity+1);

    }

}
