#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int input; //switch menu input
    signed a = 12892323; //task #1
    signed b = 454665768; //task #1
    int inputIntA, inputIntB;
    int currentPassword = 1337; //task #8 lift password
    bool needPassword = false;  //task #8
    bool menuStatus = true; //menu cycle, 0 to exit

    string inputString;
    cout << "chose a task 1-10:" << endl;

    cout << "1. Hello World;" << endl;
    cout << "3. Number + 1;" << endl;
    cout << "4. Two numbers;" << endl;
    cout << "6-7. How much u walk a day?;" << endl;
    cout << "8. House floors(lift);" << endl;
    cout << "9. Baggage +20kg;" << endl;
    cout << "10. Just code to answer 101 or 110." << endl;
    cout << endl;
    cout << "0. to EXIT;" << endl;


    while(menuStatus != false) {
        cin >> input;
        switch (input) {

            case 0:
            menuStatus = false;
            break;
            case 1:
                //1.1
                cout << "Hello world!" << endl;
                cout << "Hello " << endl << "world!" << endl;
                //1.2
                cout << a + b << endl;
            break;

                //2 //https://en.wikipedia.org/wiki/C_data_types

            case 3:  // chislo + 1
                cout << "Ey ti, wvedi chislo, bistro! ";

                cin >> inputIntA;
                cout << "not bad, twoe 4islo plus odin = " << inputIntA + 1 << endl;
            break;

            case 4: // summ dva chisla

                cout << "vremya dwuh chisel bratishka: ";
                cin >> inputIntA;
                cout << "davai vtoroe: ";
                cin >> inputIntB;
                cout << "Aii molodez. Summ is: " << inputIntA + inputIntA << endl;
            break;

                //5 //https://en.wikipedia.org/wiki/Conditional_(computer_programming)

            case 6:
            case 7: // marafonec

                //https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/conditional-operator
                cout << "skolko km v srednem hodit chelovek? answer: ";

                cin >> inputIntA;
                //                  >20               if true           else if >3          if true              else
                inputString = (inputIntA >= 20) ? "da ti marafonec" : (inputIntA <= 3) ? "malovato budet" : "a ti nichego";
                cout << inputString << endl;
            break;

            case 101: //lift
            break;
            case 9:

                for(int i = 1; i <= 5; i++){

                    cout << i;
                    cout << "sumka vesit: ";
                    cin >> inputIntA;
                    inputIntB = inputIntB + inputIntA;

                }
                if (inputIntB > 20) {
                    cout << "wes sumok bolshe 20 ";
                } else {
                    cout << "wes sumok menshe 20 ";
                }
                    cout << "i raven " << inputIntB << endl;
            break;
            case 10:
                inputIntA = 1;
                inputIntB = inputIntA + 100;
                cout << inputIntB << endl; //101
                inputIntA = 10;
                //b = a + 100;
                cout << inputIntB << endl; //101. For 110 u need redeclare B again;

            break;
            case 8:
                cout << "chose a floor(1-9): " << endl;
                cin >> inputIntA;

                while (inputIntA < 1 || inputIntA > 9 ) {

                    cout << "floor is not exist." << endl;
                    cin >> inputIntA;

                }

                    for (int i = 1; i <= inputIntA; i++) {
                        Sleep(500);   //delay, lift is moving
                        cout << i;
                        cout << " floor;" << endl;
                    }

                if (inputIntA >= 4 && inputIntA <= 6) {
                    needPassword = true;

                    while (needPassword == true) {
                    cout << "enter the password: " << endl;
                    cin >> inputIntA;
                        if(inputIntA == currentPassword) {
                            needPassword = false;
                        } else {
                            cout << "wrong password!" << endl;
                        }
                    }
                }
                cout << "ok" << endl;
            break;

            default:
                cout << "invalid input" << endl;
        }
    }
    return 0;
}
