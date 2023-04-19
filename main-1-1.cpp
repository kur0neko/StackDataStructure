#include <iostream>
#include <iomanip>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
    
    stackType<char> mystack;

    string userInputStr;

    char tempChar;

    int value;

    bool isDecimal = false;

    int numOfdecimals = 0;

    int integerNum = 0;

    double fractionalPart = 0;

    double numericValue = 0;


    cout << "Please Enter the string: ";

    cin >> userInputStr;


    
    for (unsigned int i = 0; i < userInputStr.length(); i++){
       

        tempChar = userInputStr.at(i);
        if (tempChar == '.'){

            isDecimal = true;

        }//if
        else{
            if (!isDecimal){
                
                value = (tempChar - '0');
                
                integerNum = integerNum * 10; //multiply by 10


                integerNum = integerNum + value;

            }//end if

            else{

                mystack.push(tempChar);

            }//end else
        }//end else
        
    }//end for loop

        //check wheater is decimal or not
    if (isDecimal)
    {
        // receive the next number from stack object
        while (!mystack.isEmptyStack())
        {
            numOfdecimals++;
            tempChar = mystack.top();
            mystack.pop();
            value = (tempChar - '0');
            // divide the fractionalPart value by 10.
            fractionalPart = fractionalPart / 10.0;
            fractionalPart = fractionalPart + value / 10.0;
        }
    }

    // add the values of two variables for decimal part and for whole number part.
    numericValue = integerNum + fractionalPart;

    cout << setprecision(numOfdecimals) << fixed; //set decimal number

    cout << "The numeric value of the string: " << numericValue << endl;
    return 0;
}