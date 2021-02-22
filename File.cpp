#include "File.h"



string File::changeCommaToDot(string number)
{
    string tekst = number;
    replace(tekst.begin(), tekst.end(), ',', '.');
    return tekst;
}




bool File::chceckDateWord(vector <string> date)
{
  if(date.size()!=3)
  {
      return false;
  }
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

             if(iteratorWord.length()>2)
             {
                 cout<<"Too many digits in month or day parts"<<endl;
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

vector <string> File::createVectorFromDateWords(string date)
{
        vector <string> words;
        stringstream ss(date);
        string token;
        while(getline(ss,token,'-'))
        {
            words.push_back(token);
        }
        return words;
}


string File::createStringNumberFromStringVector(vector <string> data)
{
    string stringNumber = "";
    for(int i =0; i<data.size(); i++)
    {
        stringNumber += data.at(i);
    }
    return stringNumber;
}




string File::modifyFileName(string fileName)
{
    int lengthOfWord = fileName.length()-4;
    string word = fileName.erase(lengthOfWord,4);
    return word;
}



int File::findIdNumberOfTheLastActivity()
{
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


int File::getIdNumberOfTheLastActivity()
{
    return idNumberOfTheLastActivity;
}


void File::setIdNumberOfTheLastActivity(int newLastNumberActivity)
{
    idNumberOfTheLastActivity = newLastNumberActivity;
}





void File::addToFile()
{
    int vectorIndex = 0;
    string mainTitleOfFile = modifyFileName(FILE_NAME);
    string idActivity = "", idUser="", date="", descriptionOfActivity="", money="";
    idActivity = AuxiliaryMethods::convertNumberToString(idNumberOfTheLastActivity+1);
    idUser = AuxiliaryMethods::convertNumberToString(idNumberOfUser);
    vector <string> data = {date, descriptionOfActivity, money};
    vector <string> display = {"Date as yyyy-mm-dd: ", "Description: ","Amount of money: "};
    int iter =0;
    bool todayDate = false;
    for(vector <string>:: iterator it= data.begin(); it != data.end(); it++ )
    {

        cout<<display.at(iter);
        if(vectorIndex ==0)
        {
            cout<<endl;
            cout<<"Do you want use today date Y/N?"<<endl;
            string setBool;
            cin.clear();
            cin.sync();
            cin>>setBool;
            setBool[0] = toupper(setBool[0]);
            while(setBool != "Y" || setBool != "N")
            {


                if(setBool == "Y")
                {
                    todayDate = true;
                    break;
                }
                else if(setBool=="N")
                {
                    todayDate = false;
                    break;
                }
                else
                {
                    cout<<"Wrong answear, try again:";
                    cin.clear();
                    cin.sync();
                    cin>>setBool;

                }

            }

        }

        if(vectorIndex ==1 || vectorIndex==2)
        {
            *it = AuxiliaryMethods ::getText();
        }
        if(vectorIndex == 0 && todayDate==false)
        {
            cout<<"Date: ";
            *it = AuxiliaryMethods ::getText();
            while(*it=="")
            {
              cout<<"Date is empty. Please write a date: ";
              *it = AuxiliaryMethods ::getText();
            }
            vector <string> word = createVectorFromDateWords(*it);
            bool checkingDatePoint = chceckDateWord(word);
            while(checkingDatePoint==false)
            {
                cout<<"Date is wrong, try again: ";
                data[0] = AuxiliaryMethods::getText();
                while(data[0]=="")
                {
                  cout<<"Date is empty. Please write a date: ";
                  data[0] = AuxiliaryMethods ::getText();
                }
                checkingDatePoint = chceckDateWord(createVectorFromDateWords(data[0]));

            }
        }
        if(vectorIndex ==0 && todayDate==true)
        {

                *it = Date::getTodayDate();
        }
        if(vectorIndex==2)
        {
            *it = changeCommaToDot(*it);
        }
        vectorIndex++;
        iter++;

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
