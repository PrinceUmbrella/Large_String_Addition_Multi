
/*/////////////////////////////////////////////////////////////
// Name:Leoul Tilahun                                        //
// Date: 02/15/2019                                          //
/////////////////////////////////////////////////////////////*/


/*/////////////////////////////////////////////////////////////
//       #1 Question                                         //
//       Set One                                             //
/////////////////////////////////////////////////////////////*/
#include <set1>
void delete_Once(String & inputString, char deleteChar)
{
    string temp;
    Create(temp);
    char checker;
    int countt = 0;

    while (!isEmpty(inputString))
    {
        checker = delete_At(inputString, 0);
        
        if ((checker != deleteChar) ||
            (checker == deleteChar && countt != 0))
        {
            Append(temp, checker);
        }
        else
        {
            countt = countt + 1;
        }
    }

    while (!isEmpty(temp))
    {
        checker = delete_At(inputString, 0);
        Append(inputString, checker);
    }
}

/*/////////////////////////////////////////////////////////////
//       #2 Question                                         //
//       Set Two                                             //
/////////////////////////////////////////////////////////////*/

#include <set2>
void delete_Once(String & inputString, char deleteChar)
{

    int charPosition;
    char finalDeleted;

    charPosition = Pos(inputString, deleteChar);
    finalDeleted = Delete_At(inputString, charPosition);
}

























/*/////////////////////////////////////////////////////////////
//       #3 Question                                         //
//       Set Three                                           //
/////////////////////////////////////////////////////////////*/

#include <set3>
void delete_Once(String & inputString, char deleteChar)
{
    String temp;
    Create(temp);
    char tempChar;
    int len;
    int position;
    bool trigger = false;

    
    len = Length(inputString);
    position = Pos(inputString, deleteChar);

    for (int i = 0; i < len; i++){
        tempChar = Get_char(inputString, i);
        if(i != position && !trigger){
            Insert_At(temp, tempChar, i);
        }
        else{
            Insert_At(temp, tempChar, i-1);
            trigger = true;
        }
        
    }

    for (int i = 0; i < len; i++){
        
        tempChar = Delete_First(inputString);
    }
    
    for (int i = 0; i < len; i++){
        
        tempChar = Delete_First(temp);
        Insert_At(inputString, tempChar, i);
    }
}

