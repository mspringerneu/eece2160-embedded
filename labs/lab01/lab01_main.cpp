/*
 * Project: lab01_main.cpp
 * Author: 	Matthew Springer
 * Date:	Created on Jan 17, 2017
 * Purpose:	This program initializes an array and allows for dynamic array modification via user input
 */

#include <iostream>
#include <string>
#include "lab01_methods.h"

using namespace std;

double * v;
int arr_index;
int size;
int * input;
bool executing = true;

/*
 * Function:    Initialize
 * Input:       None
 * Output:      None
 * Purpose:     Initializes an empty array of size 2
 */
void Initialize() {
    arr_index = 0;
    size = 2;
    v = new double[size];
    input = new int;
}

/*
 * Function:    Finalize
 * Input:       None
 * Output:      None
 * Purpose:     Deletes the dynamically allocated global variables
 */
void Finalize() {
    delete [] v;
    v = NULL;
    delete input;
    executing = false;
}

/*
 * Function:    ReadUserInput
 * Input:       None
 * Output:      None
 * Purpose:     Read's and returns the user's input from cin
 *              if an invalid input is given
 */
void ReadUserInput() {
    cout << "Select an option: ";
    cin >> *input;
}

/*
 * Function:    HandleUserInput
 * Input:       None
 * Output:      None
 * Purpose:     Calls the appropriate function based on the user input, or re-displays the menu
 *              if an invalid input is given
 */
void HandleUserInput() {
    switch (*input) {
        case 1:
            cout << "You selected 'Print the array'" << endl;
            break;
        case 2:
            cout << "You selected 'Append element at the end'" << endl;
            break;
        case 3:
            cout << "You selected 'Remove last element'" << endl;
            break;
        case 4:
            cout << "You selected 'Insert one element'" << endl;
            break;
        case 5:
            cout << "You selected 'Exit'" << endl;
            Finalize();
            break;
        default:
            cout << "You have entered an invalid input.  Please enter the number that corresponds with the command you wish to execute.  Re-displaying main menu..." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            break;
    }
    
}

/*
 * Function:    PrintMainMenu
 * Input:       None
 * Output:      None
 * Purpose:     Print's the main program's menu, detailing user modifications
 */
void PrintMainMenu() {
    cout << "Main menu:" << endl << endl;
    cout << "1. Print the array" << endl;
    cout << "2. Append element at the end" << endl;
    cout << "3. Remove last element" << endl;
    cout << "4. Insert one element" << endl;
    cout << "5. Exit" << endl << endl;
}

/*
 * Function:    Main
 * Input:       None
 * Output:      None
 * Purpose:     Print's the main program's menu, detailing user modifications
 */
int main() {
    Initialize();
    while (executing) {
        PrintMainMenu();
        ReadUserInput();
        HandleUserInput();
    }
    return 0;
}
