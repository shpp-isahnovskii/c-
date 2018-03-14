#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;
/**task #23 search does int exist or not in array.
*@param (1)number what will be searching in (2)some array with (3)n-elements in it.
*@return return true of false.
*/
int guessComand(int randNum, int housesNumbers[], int N) {

    for(int i = 0; i < N; i++) {
        if(randNum == housesNumbers[i]) {

            return 1;
            break;
        }
    }
    return 0;
}
/**task #24 filter with min and max values.
*@param (1) input number, (2) it's minimum value, (3) it's maximum value.
*@return return number that meets the requirements.
*/
int verification(int &number, int minValue, int maxValue) {
    cin >> number;
    while (number < minValue || number > maxValue) {
        cout << "Invalid input!" << endl;
        cin >> number;
    }
    return number;
}

/**task #25 print thing line.
*@param array with highest number - to know how many spaces and stars will be print by function.
* i - current print stage, current line what are printing.
*/
int printThingLine(int thingArray[], int largestPart, int i) {
    for (int j = thingArray[i] / 2; j < largestPart / 2; j++) {
        cout << " ";
    }
    for (int h = 0; h < thingArray[i]; h++) {
        cout << "*";
    }
    cout << endl;
   return 0;
}

//int largestPart(int &arrayList, int N) {
//    int maxValue = 0;

//    for(int i = 0; i < N; i++) {
//        if(arrayList[i] > maxValue) {
//            maxValue = arrayList[];
//        }
//    }
//    return maxValue;
//}

//printThing(int &arrayList, int largestInput, int N) {
//    int z = 0;
//    for (int i = 0; i < N; i++) {
//    z = arrayList[i];
//    cout << " ";

//    }

//}
/**task #30 Print an array.
*@param (1) subject array, (2) its size.
*/
int printAnArray(int someArray[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cout << someArray[i] << " | ";
    }
    cout << endl << endl;
    return 0;
}
/**task #30 Standard solution without C++ special command std::reverse().
*I'm copy it from world web. Sry, link was to laaarge :).
*@param (1) subject array, (2) its size.
*@return reversed array.
*/
int reverseArray( int a[], int n ) {

    for ( int i = 0; i < n / 2; i++ )
    {
        int tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1 ] = tmp;
    }
    return *a;
}
int main() {

    int input; //switch menu input
    bool menuStatus = true; //menu cycle, 0 to exit

    int housesAmount = 10; //task #23
    int maxHouseNumber = 30; //task #23
    int randNum; //task #23, #24, #25
    int arrayOfHouses[housesAmount]; //task #23

    int bankCards[10]; //task #24 - 10 cards
    int transaction; //task #24 - money value +input or -output
    int firstCard = 0; //task #24 -first card
    int lastCard = 9; //task #24 -last of..
    int minValue = -1000; //task #24 max -outgoing
    int maxValue = 1000; //task #24 max +incoming

    int maxThingSize = 20; //task #25
    int thingArray[maxThingSize]; //task #25 - maximum size of thing
    int counter; //task #25 - counter for array need to know how many numbers user are already input
    int largestPart; //task #25 - largest number in the array

    int a; // task #26
    int element; // task #26

    cout << "chose a task 21-30:" << endl;

    cout << "23. Ten houses;" << endl;
    cout << "24. Ten bank cards;" << endl;
    cout << "25. Centered thing;" << endl;
    cout << "30. Last task." << endl;
    cout << endl;
    cout << "0. to EXIT;" << endl;


    while(menuStatus != false) {
        cin >> input;
        switch (input) {

            case 0:
            menuStatus = false;
            break;

            case 23: //houses

                cout << "Ten random houses are generated:" << endl;
                cout << endl;
                    srand(time(NULL));
                    for (int i = 0; i < housesAmount; i++) {
                        randNum = 1 + rand() % maxHouseNumber;
                        arrayOfHouses[i] = randNum;
                        cout <<"  "<< randNum <<"  ";
                    }

                    cout << endl << endl;
                    cout <<"Chose a number. Input 0 to exit." << endl;

                    cin >> randNum;
                    while (randNum != 0) {

                        if (guessComand(randNum, arrayOfHouses, housesAmount) == 1) { //can be 1 or 0

                            cout << "! Yes, i know that house." << endl;

                            } else {

                            cout << "? Sorry, don't know that house." <<endl;
                            }

                        cin >> randNum;
                    }
                    cout <<"Exit." << endl;
                    return 0;
            break;
            case 24: //bank cards

                for(int i = 0; i < sizeof(bankCards)/sizeof(int); i++) { //array initialization
                    bankCards[i] = 0;
                }

                while(transaction != 0) {

                cout << "Input card number "<< firstCard <<"-"<< lastCard << ":" << endl;

                verification(randNum, firstCard, lastCard); //card range check

                cout << "card confirmed, now enter value in range " << minValue << " to " << maxValue << ":" << endl;
                cout <<"Input transaction value 0 to exit."<< endl;
                verification(transaction, minValue, maxValue); //value range check

                bankCards[randNum] = bankCards[randNum] + transaction; //input transaction into the bank card cell

                for(int i = 0; i < sizeof(bankCards)/sizeof(int); i++) {
                    cout << bankCards[i];
                    cout << "  ";

                }
                cout << endl;
            }
            cout <<"Exit." << endl;
            return 0;
            break;

            case 25: //centered thing

                cout << "Enter even numbers, and build your centered thing." << endl
                << "To finish enter 0." << "Now go: " << endl;

                counter = 0;
                largestPart = 0;
                cin >> randNum;

                while(randNum != 0 || counter > maxThingSize) {
                    if(randNum % 2 != 1) {
                        cout << "Wrong number. Enter only even numbers: " << endl;
                        cin >> randNum;
                    }
                    thingArray[counter] = randNum;

                    if(largestPart < randNum) {
                        largestPart = randNum;
                    }
                    cin >> randNum;
                    counter++;
                }
                //print thing
                for(int i = 0; i < counter; i++) {
                    printThingLine(thingArray, largestPart, i);
                }

            break;
            case 30: //reverse array
                cout << "Enter array range: " << endl;
                cin >> a;
                int m[a];

                for(int i = 0; i < a; i++ ) {
                   cin >> element;
                   m[i] = element;
                }

                printAnArray(m, a);

                *m = reverseArray( m, a); //save reversed array

                printAnArray(m, a);

            break;
            default:
                cout << "invalid value" << endl;
            break;
        }
    }
    return 0;
}
