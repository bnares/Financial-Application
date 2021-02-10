#include "File.h"

#include <iostream>

using namespace std;


string File :: changeCommaToDot(string number)
{
    string tekst = number;
    replace(tekst.begin(), tekst.end(), ',', '.');
    cout<<"after modyfication with comma: "<<tekst<<endl;
    return tekst;
}




bool File :: chceckDateWord(vector <string> date)
{
  for(vector <string>:: iterator it = date.begin(); it!=date.end(); it++)
  {
      string iteratorWord = *it;
      for(int i = 0; i<iteratorWord.length(); i++)
      {
          if(!isdigit(iteratorWord[i]))
          {
              return false;
          }
          if( it == date.begin()+1 || it == date.end()-1)
          {
             if(iteratorWord.length()<2)
             {
                 cout<<"if number in day or month position is less than 10, use prefix 0 before number for example 2020-03-08"<<endl;
                 return false;
             }
          }
      }
  }
  int year = AuxiliaryMethods::convertStringToNUmber(date[0]);
  int month = AuxiliaryMethods::convertStringToNUmber(date[1]);
  int day = AuxiliaryMethods::convertStringToNUmber(date[2]);
  Date currentDate(day, month, year);
  if(currentDate.ileDniMaMiesiac())
  {
    return true;
  }
  else
  {
      return false;
  }


}

vector <string> File :: createVectorFromDateWords(string date)
{
        vector <string> words;
        stringstream ss(date);
        string token;
        while(getline(ss,token,'-'))
        {
            cout<<"token: "<<token<<endl;
            words.push_back(token);
        }
        return words;
}




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



    //int lengthOfTitle = FILE_NAME.length()-4;
    //string mainTitleOfFile = FILE_NAME.erase(lengthOfTitle,4);
    int vectorIndex = 0;
    string mainTitleOfFile = modifyFileName(FILE_NAME);
    string idActivity = "", idUser="", date="", descriptionOfActivity="", money="";
    idActivity = AuxiliaryMethods::convertNumberToString(idNumberOfTheLastActivity+1);
    idUser = AuxiliaryMethods::convertNumberToString(idNumberOfUser);
    vector <string> data = {date, descriptionOfActivity, money};
    for(vector <string>:: iterator it= data.begin(); it != data.end(); it++ )
    {
        cout<<"Write subsequently date as yyyy-mm-dd, descritpion, amount of money: "<<endl;
        *it = AuxiliaryMethods ::getText();
        if(vectorIndex == 0)
        {
            vector <string> word = createVectorFromDateWords(*it);
            bool checkingDatePoint = chceckDateWord(word);
            while(checkingDatePoint==false)
            {
                cout<<"Date is wrong, try again"<<endl;
                data[0] = AuxiliaryMethods::getText();
                checkingDatePoint = chceckDateWord(createVectorFromDateWords(data[0]));

            }
        }
        if(vectorIndex==2)
        {
            *it = changeCommaToDot(*it);
        }
        vectorIndex++;

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
