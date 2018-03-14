#include <iostream>
#include <stdio.h>

using namespace std;

/** task #12 counting numbers 1,2,3,4..  etc.
*@param first number what we are starting from, finishing number end with, mode for: "only even numbers".
*/
int printNumbersWithComas(int startNumber, int finishNumber, bool evenMode) {

        if (evenMode == true && finishNumber % 2 == 1) { //make odd number even again
            finishNumber = finishNumber - 1;
        }

        while (startNumber != finishNumber) {

            if (evenMode == true) { //even mode

                if(startNumber %2 != 1) {
                    cout << startNumber;
                    cout << ",";
                }

            } else {
                cout << startNumber;
                cout << ",";
            }
            if(startNumber > finishNumber) { //increase or decrease count
                startNumber--;
            } else {
                startNumber++;
            }
        }
        cout << startNumber << "." << endl; // last number will be print separately, out from cycle
        return 0;
}

/** task #13-14 figures collection what program deal with.
*@param size to know how build current row, current print cycle, N algoritm from the library.
*/
int printLineFigure(int figureSize, int cycleCounter, int figureType){
    if(figureType == 1) {
        for(int i = 0; i < figureSize; i++) {
            cout << "*";
        }
    }
    if(figureType == 2) {
        while(cycleCounter >= 0) {
            cout << "*";
            cycleCounter--;
        }
    }
    if(figureType == 3) {
        while(cycleCounter < figureSize) {
            cout << "*";
            cycleCounter++;
        }
    }
    if(figureType == 4) {
        for (int i = 0; i < cycleCounter; i++) {
            cout << " ";
        }
        for (int j = 0; j < figureSize - cycleCounter; j++) {
            cout << "*";
        }
    }
    return 0;
}

/** task #13-14 cycle to print figures line by line.
*@param size to know how many rows to build, different figures from library to print.
*/
int printFigure(int figureSize, int figureType) {
    for(int i = 0; i < figureSize; i++) {
        printLineFigure(figureSize, i, figureType);
        cout << endl;
    }
    return 0;
}


/** task #15 print line one of our tree.
*At the end we will get a pyramid.
*@param figure (1)total and (2)current sizes are used to take balance between spaces and stars.
*/
int printTreeLine(int figureSize, int currentSize) { //line of tree

    for(int i = 0; i < currentSize - 1; i++) {  // delete space from start line
        cout << " ";
    }
    for(int i = 0; i < (figureSize - currentSize) * 2 + 1 ; i++) { // * 2 + 1 are additional cycles to build back side for tree
        cout << "*";

    }
        cout << endl;
    return 0;
}

/** task #15 print root for our tree
*@param size of figure indicate how many spaces needed until stump (*) will be planted.
*/
int printTreeStump(int figureSize) { //last part - is a root for a tree

    for(int i = 0; i < figureSize - 1;i++) {
        cout << " ";
    }
    cout << "*" << endl;
    return 0;
}
//task #15 print a Tree line by line

/** task #15 complex function, what build a tree. Include printPyramid function and printStump.
*@param size of tree, amount of lines that would be printed.
*/
int printTree(int figureSize) {
    int currentSize = figureSize;
    while(currentSize > 0) {

        printTreeLine(figureSize, currentSize);

        currentSize--;

    }
    printTreeStump(figureSize);
    return 0;
}


/** task #16 and 29. Counting current number and next number.
*@param first and last numbers in row to summ.
*@return summ of numbers in row between A and B.
*/
int numbersRowSum(int startNumber, int lastNumber) {
    for (int i = startNumber + 1; i <= lastNumber; i++) { //now: start number = 0 + 1; startNumber = 1 + 2; startNumber = 3 + 3.. etc.
        startNumber = startNumber + i;                    //If start number = 1 then i = 2, then: startNumber = 1 + 2; startNumber = 3 + 3.. etc.
    }
    return startNumber;
}



int main()
{
    bool menuStatus = true;
    int input; //switch menu input

    int startNumber;    //task #12, 16
    int finishNumber;   //task #12, 16
    bool evenMode;      //task #12

    int figureType;     //task #13-14
    int figureSize;     //task #13-14, 15

    int summOfRow;      //task #16
    int value;          //task #17, 19
    int valueToPrint;   //task #17
    int a, b, c;        //task #19

    cout << "Chose a task 11-20:" << endl;
    cout << "12. Numbers(1 to N);" << endl;
    cout << "13-14. Figures;" << endl;
    cout << "15. Tree;" << endl;
    cout << "16 and 29. Amount of numbers between A and B;" << endl;
    cout << "17. Highest number input;" << endl;
    cout << "19. Find summ of numbers in three-digit number" << endl;
    cout << endl;
    cout << "0. EXIT." << endl;

    while(menuStatus != false) {
        cin >> input;

        switch(input) {

            case 0:
                menuStatus = false;
            break;
            case 12: //numbers

                cout << "   1. numbers & comas;" << endl
                     << "   2. reverse count;" << endl
                     << "   3. even numbers." << endl;
                cin >> input;
                switch(input) {

                    case 1: //..with comas
                        cout << "How many numbers u wanna to print?: ";

                        startNumber = 1;
                        evenMode = false;
                        cin >> finishNumber;
                        //                          1           n          off
                        printNumbersWithComas(startNumber, finishNumber, evenMode);

                    break;


                    case 2: //..reverse
                        cout << "How many numbers u wanna to print reverse?: ";

                        finishNumber = 1;
                        evenMode = false;
                        cin >> startNumber;
                        //                          n           1           off
                        printNumbersWithComas(startNumber, finishNumber, evenMode);

                    break;

                    case 3: //..even
                        startNumber = 1;

                        cout << "Input N value. Even numbers will be printed form " << startNumber << " to N: ";

                        evenMode = true;
                        cin >> finishNumber;
                        //                          1           n           on
                        printNumbersWithComas(startNumber, finishNumber, evenMode);

                    break;
                    default:
                        cout << "Invalid input" << endl;
                    break; // end of submenu inside #12
                    }
            break; //#12 end
            case 13: //figures
            case 14: //figures
                cout << "CHOSE YOUR OBJECT:" << endl
                <<"   **" << endl
                <<"1. **" << endl
                          << endl
                <<"   * " << endl
                <<"2. **" << endl
                          << endl
                <<"   **" << endl
                <<"3. * " << endl
                          << endl
                <<"   **" << endl
                <<"4.  *" << endl;

                cin >> input;

                    switch(input) {
                    case 1: //object1        **
                            //               **
                        figureType = 1;
                        cout  << "What the size?: " << endl;
                        cin >> figureSize;
                        printFigure(figureSize, figureType);
                    break;

                    case 2: //object2        *
                            //               **
                        figureType = 2;
                        cout  << "What the size?: " << endl;
                        cin >> figureSize;
                        printFigure(figureSize, figureType);
                    break;

                    case 3: //object3        **
                            //               *
                        figureType = 3;
                        cout  << "What the size?: " << endl;
                        cin >> figureSize;
                        printFigure(figureSize, figureType);
                    break;

                    case 4: //object4        **
                            //                *
                        figureType = 4;
                        cout  << "What the size?: " << endl;
                        cin >> figureSize;
                        printFigure(figureSize, figureType);

                    break;
                    default:
                    cout << "Invalid input" << endl;
                    break;
                    }
            break;
            case 15:
                //    *
                //   ***
                //  *****
                // *******
                //    *
                cout  << "Input tree height: " << endl;
                cin >> figureSize;
                figureSize = figureSize - 1; //one star fill be our "Stump". We will build pyramide, then add that stump separately
                printTree(figureSize);
            break;
            case 16: //1+2+3+4+5.. etc.
            case 29:
                cout << "Enter A: ";
                cin >> startNumber;
                cout << "Enter B: ";
                cin >> finishNumber;

                cout << numbersRowSum(startNumber, finishNumber) << endl;

            break;
            case 17: //highest number
                cout << "Input numbers, program will return highest even number from them." << endl
                <<" Input 0 to see result:" <<endl;
                cin >> value;
                if(value % 2 != 1) {
                valueToPrint = value;
                }
                while (value != 0) {
                    cin >> value;
                    if(valueToPrint < value && value % 2 != 1) {
                        valueToPrint = value;
                    }
                }

                cout << "Highest number is: " << valueToPrint << endl;

            break;
            case 19: //three-digit number - find a summ of numbers in it.
                cout << "Input three-digit number:" << endl;
                cin >> value;

                while (value >= 1000 || value <= 99) {
                    cout << "invalid value!" << endl << "Input 3-digit value: " <<endl;
                    cin >> value;
                }
                    a = value /100; // 100-hs
                    b = value % 100 / 10; //10-hs
                    c = value -  ((a * 100) + (b * 10)); //1-e
                    cout << "three values " << a <<","<< b <<","<< c << "." << endl;
                    cout <<"Summ is: " << a + b + c << endl;

            break;
            default:
                cout << "Invalid input value" << endl;
            break;

        }
    }
    return 0;
}
