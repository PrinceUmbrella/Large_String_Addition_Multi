#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*////////////////////////////////////////////////////////////////////
//              Constants                                           //
///////////////////////////////////////////////////////////////////*/

const int BASE = 10;
const int USERINPUT_LENGTH_LIMIT = 15;
const int NUMBER_OF_INPUT_LIMIT= 12;
const int NUMBER_OF_MULTIPLICATION = 2;

/*////////////////////////////////////////////////////////////////////
//              Prototypes                                          //
///////////////////////////////////////////////////////////////////*/

int power(int size);
int getNumberOfInput();
void openningStatement();
string addComma(string number);
bool isCorrect(string userInput);
int changetoInt(string userInput);
string getUserInput(int inputNumber);
string removeSpaces(string userInput);
string removeLeadingZeros(string userInput);
bool isNumberOfInputCorrect(string userInput);
string* multiplyNumbers(string number1, string number2);
string  multiplication(string number1, char multiplying);
string  addition(string firstNumber, string secondNumber);
void addCommaToArray (string* numberList, int lengthOfArray);
void printNumber(string* numberArray, int maxlength);
void printMultiOnly(string* numberArray, int maxLength, int lenOfArray);
string  InsertChar(string smallestNum, int countt, bool inFront, char character);

int main()
{
    string userInput;
    int numberOfInputs, finalLength;
    string *product, *summ, startProduct, *multiNum, quit;
    char add, multi;

    openningStatement();

    numberOfInputs = getNumberOfInput();
    cout<< endl;

    summ = nullptr;
    summ = new string [numberOfInputs + 1];
    summ[numberOfInputs] = "0";

    for (int i = 0; i < numberOfInputs; i++)
    {
        summ[i] = getUserInput(i);
        summ[numberOfInputs] = addition(summ[i], summ[numberOfInputs]);
    }

    product = nullptr;
    startProduct = "1";
    multiNum = new string[NUMBER_OF_MULTIPLICATION];
    for (int i = 0; i < NUMBER_OF_MULTIPLICATION; i++)
    {
        product = multiplyNumbers(startProduct, summ[i]);
        startProduct = product[summ[i].length()];
        multiNum[i] = summ[i];
    }

    finalLength = summ[NUMBER_OF_MULTIPLICATION - 1].length();

    cout<<endl<<"The sum of: "<< endl << endl;
    addCommaToArray(summ, numberOfInputs);
    printNumber(summ, numberOfInputs);

    cout<< endl<<"The product of:"<< endl << endl;
    addCommaToArray(product, finalLength);

    printMultiOnly(multiNum, product[finalLength].length(), NUMBER_OF_MULTIPLICATION);
    printNumber(product, finalLength);

    cout<<endl<< "Press any key to contiue . . .";
    getline(cin, quit);
}

/*////////////////////////////////////////////////////////////////////
    Gets and Verifies the user input and returns a string
///////////////////////////////////////////////////////////////////*/

string getUserInput(int inputNumber)
{
    string userInput;
    cout<< "Input number #" << inputNumber + 1 << " -> ";
    getline(cin, userInput);

    userInput = removeSpaces(userInput);
    userInput = removeLeadingZeros(userInput);

    while(isCorrect(userInput))
    {
        cout<< "Incorrect Input!!! "<< endl;
        cout<<"Plese enter Input #" << inputNumber + 1<< " again -> ";
        getline(cin,userInput);

        userInput = removeSpaces(userInput);
        userInput = removeLeadingZeros(userInput);
    }

    return userInput;
}
/*//////////////////////////////////////////////////////////////
    Checks if the input has correct length, and if it is with
    in the base limit.
/////////////////////////////////////////////////////////////*/
bool isCorrect(string userInput)
{
    bool notCorrect;
    char baseLimit;
    notCorrect = false;
    baseLimit = '0' + (BASE - 1);

    if(userInput.length() < 1 || userInput.length() > USERINPUT_LENGTH_LIMIT)
    {
        notCorrect = true;
    }
    for(int i = 0; i < userInput.length(); i++)
    {
        if(userInput[i] < '0' || userInput[i] > baseLimit)
        {
            notCorrect = true;
        }
    }
    return notCorrect;
}

/*//////////////////////////////////////////////////////////////
    Removes the leading the zero from the input
/////////////////////////////////////////////////////////////*/

string removeLeadingZeros(string userInput)
{
    string finalString;
    finalString = "";
    bool firstNonZero = true;
    int nonZeroPosition;

    for (int i = 0; i < userInput.length(); i++)
    {
        if(userInput[i] != '0' && firstNonZero)
        {
            nonZeroPosition = i;
            firstNonZero = false;
        }
    }

    if(firstNonZero)
    {
        nonZeroPosition = userInput.length() - 1;
    }

    for (int i = nonZeroPosition; i < userInput.length(); i++)
    {
        finalString += userInput[i];
    }

    return finalString;
}

/*////////////////////////////////////////////////////////////////
    Gets and returns the number of times the user enters a number
///////////////////////////////////////////////////////////////.*/

int getNumberOfInput()
{
    int finalUserInput;
    string userInput;
    userInput = "";
    cout<<endl<<"How many numbers? -> ";
    getline(cin, userInput);

    while(isNumberOfInputCorrect(userInput))
    {
        cout<< "Incorrect Input!!! Please Enter How many numbers? -> ";
        getline(cin, userInput);
    }

    finalUserInput = changetoInt(userInput);

    return finalUserInput;
}

/*//////////////////////////////////////////////////////////////
    Checks the if the number of times the user enters a number
/////////////////////////////////////////////////////////////*/

bool isNumberOfInputCorrect(string userInput)
{
    bool notCorrect;
    int userInput_int;
    notCorrect = false;

    if(userInput.length() < 1)
    {
        notCorrect = true;
    }

    for(int i = 0; i < userInput.length(); i++)
    {
        if(userInput[i] < '0' || userInput[i] > '9')
        {
            notCorrect = true;
        }
    }
    userInput_int = changetoInt(userInput);
    if(userInput_int < 2 || userInput_int > NUMBER_OF_INPUT_LIMIT)
    {
        notCorrect = true;
    }

    return notCorrect;
}

/*//////////////////////////////////////////////////////////////
    Gets a string and returns the integer conversion of the
    number.
/////////////////////////////////////////////////////////////*/

int changetoInt(string userInput)
{
    int finalInt;
    int countt;

    finalInt = 0;
    for(int i = 0; i < userInput.length(); i++)
    {
        finalInt += (userInput[i] - '0')*power(userInput.length() - i - 1);
    }

    return finalInt;
}

/*//////////////////////////////////////////////////////////////
    returns the Power of the number.
/////////////////////////////////////////////////////////////*/

int power(int size)
{
    int finalPower;
    finalPower = 1;

    for (int i = 0; i < size; i++)
    {
        finalPower *= 10;
    }
    return finalPower;
}

/*//////////////////////////////////////////////////////////////
    Removes the space from the input
/////////////////////////////////////////////////////////////*/

string removeSpaces(string userInput)
{
    string finalString;
    int lengthOfString = 0;
    finalString = "";

    while (lengthOfString < userInput.length())
    {
        if (userInput[lengthOfString] == ' ')
        {
            lengthOfString++;
        }
        else
        {
            finalString += userInput[lengthOfString];
            lengthOfString++;
        }
    }
    return finalString;
}

/*//////////////////////////////////////////////////////////////
    Prints the Number in the given format for addition
/////////////////////////////////////////////////////////////*/

void printNumber(string* numberArray, int maxLength)
{
    string hyphen;

    for(int i = 0; i < maxLength - 1; i++)
    {
        cout<<setw(numberArray[maxLength].length() - numberArray[i].length() + 3)<< " "<< numberArray[i]<< endl;
    }
    cout<<"+)"<<setw(numberArray[maxLength].length() - numberArray[maxLength - 1].length() + 1)<<" "<<numberArray[maxLength - 1]<< endl;

    hyphen = InsertChar(hyphen, numberArray[maxLength].length() + 3, true, '-');
    cout<<hyphen<<endl;
    cout<< setw(3) << " "<< numberArray[maxLength] <<endl;


}

/*//////////////////////////////////////////////////////////////
    Prints the Number in the given format for multiplication
/////////////////////////////////////////////////////////////*/

void printMultiOnly(string* numberArray, int maxLength, int lenOfArray)
{
    string hyphen;

    for (int i = 0; i < lenOfArray - 1; i++)
    {
        numberArray[i] = addComma(numberArray[i]);
        cout<< setw(maxLength - numberArray[i].length() + 3)<<" "<< numberArray[i]<< endl;
    }
    numberArray[lenOfArray- 1] = addComma(numberArray[lenOfArray- 1]);
    cout<<"*)"<<setw(maxLength- numberArray[lenOfArray - 1].length() + 1)<<" "<<numberArray[lenOfArray- 1]<< endl;
    hyphen = InsertChar(hyphen, maxLength + 3, true, '-');
    cout<<hyphen<<endl;
}

/*//////////////////////////////////////////////////////////////
    Adds the character given to the string given to the number
    of times it was inputted then returns the final string.
/////////////////////////////////////////////////////////////*/

string InsertChar(string smallestNum, int countt, bool inFront, char character)
{

    string numberOfChars;

    numberOfChars = "";

    for (int i = 0; i < countt; i++)
    {
        numberOfChars += character;
    }
    
    if(inFront)
    {
        smallestNum = numberOfChars + smallestNum;
    }
    else{
        smallestNum = smallestNum + numberOfChars;
    }
    return smallestNum;
}

/*//////////////////////////////////////////////////////////////
    Gets two strings and adds them together and returns the
    final answer.
/////////////////////////////////////////////////////////////*/

string  addition(string firstNumber, string secondNumber)
{

    string numberOfZeros;
    string largestNum, smallestNum;
    string  finalSum;
    int fromLargest, fromSmallest;
    int carry, prevCarry, sumOfNumbers, lengthDifference;
    char pass;

    if (firstNumber.length() <= secondNumber.length()){
        largestNum  = secondNumber;
        smallestNum = firstNumber;
    }
    else{
        largestNum  = firstNumber;
        smallestNum = secondNumber;
    }

    lengthDifference = largestNum.length() - smallestNum.length();
    smallestNum = InsertChar(smallestNum, lengthDifference, true, '0');


    finalSum = "";
    carry = 0;
    prevCarry = 0;
    sumOfNumbers = 0;

    for (int i = largestNum.length()-1; i >= 0; i--)
    {

        fromLargest  = largestNum[i] - '0';
        fromSmallest = smallestNum[i] - '0';
        sumOfNumbers = fromLargest + fromSmallest;
        sumOfNumbers += prevCarry;
        carry = sumOfNumbers / BASE;
        sumOfNumbers = sumOfNumbers % BASE;

        pass = sumOfNumbers + '0';
        // cout << "From Large " << largestNum << endl;
        // cout << "From Small " << smallestNum << endl;
        // cout << "Sum of Numbers " << sumOfNumbers << endl;
        // cout << "Carry " << carry << endl;        
        // cout << "Pass " << pass << endl;

        finalSum  = pass + finalSum;
        // cout << "Final Sum " << finalSum << endl;
        prevCarry = carry;

    }
    if (carry > 0)
    {
        pass = prevCarry + '0';
        finalSum = pass + finalSum;
    }
    return finalSum;

}

/*//////////////////////////////////////////////////////////////
    Gets a strings and character then multiplies them
    together and returns the final answer.
/////////////////////////////////////////////////////////////*/

string multiplication(string number1, char multiplying)
{
    char pass;
    int multiplied, multiplying_int, product, carry, prevCarry;
    string finalProduct;

    multiplying_int = multiplying - '0';
    finalProduct = "";
    prevCarry = 0;

    for (int i = number1.length() - 1; i >= 0 ; i--)
    {
        multiplied = number1[i] - '0';
        product = multiplied * multiplying_int;
        product += prevCarry;
        carry = product / BASE;
        product = product % BASE;
        pass = product + '0';
        finalProduct = pass + finalProduct;

        prevCarry = carry;
    }
    if (carry > 0)
    {
        pass = prevCarry + '0';
        finalProduct = pass + finalProduct;
    }
    return  finalProduct;
}

/*//////////////////////////////////////////////////////////////
    Gets two strings and then multiplies them by call other
    functions and returns an array which has the steps in the
    middle and the final answer.
/////////////////////////////////////////////////////////////*/

string* multiplyNumbers(string number1, string number2)
{
    string* totalMulti;
    string finalSum;
    int stringLen;

    stringLen = number2.length();
    totalMulti = new string [stringLen + 1];

    for (int i = number2.length() - 1; i >= 0; i--)
    {
        totalMulti[number2.length() - 1 - i] = multiplication(number1, number2[i]);
        totalMulti[number2.length() - 1 - i] = InsertChar(totalMulti[number2.length() - 1 - i], number2.length() - 1 - i, false, '0');
    }

    finalSum = "";

    for(int i = 0; i < number2.length(); i++)
    {
        finalSum = addition(totalMulti[i], finalSum);
    }

    totalMulti[stringLen] = finalSum;

    return totalMulti;
}

/*//////////////////////////////////////////////////////////////
    Adds the comma to the user Input
/////////////////////////////////////////////////////////////*/

string addComma(string number)
{
    string numberwithComma, p;
    int subStrCount = 0;
    p = "";

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if(subStrCount == 2 && i != 0){
            p += number[i];
            numberwithComma = ","+ p + numberwithComma;
            subStrCount = 0;
            p = "";
        }
        else
        {
            numberwithComma = number[i] + numberwithComma;
            subStrCount++;
        }
    }

    return numberwithComma;
}

/*//////////////////////////////////////////////////////////////
    adds comma to every element in the array
/////////////////////////////////////////////////////////////*/

void addCommaToArray (string* numberList, int lengthOfArray)
{

    for (int i = 0; i <= lengthOfArray; i++)
    {
        numberList[i] = addComma(numberList[i]);
    }
}

/*//////////////////////////////////////////////////////////////
    Prints this statement on the begining of the program.
/////////////////////////////////////////////////////////////*/

void openningStatement()
{

    cout<< "This program adds 2 and up to " << NUMBER_OF_INPUT_LIMIT <<" very large number accurately"<< endl;
    cout<< "It multiplies the first 2 number and shows the intermediate steps of the product."<< endl;
    cout<< "The program will remove any spaces you entered in addition to removing leading zeros"<< endl;
    cout<< "There is a LENGTH LIMIT of "<< USERINPUT_LENGTH_LIMIT << endl;
}





