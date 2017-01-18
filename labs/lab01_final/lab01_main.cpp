/*
 * Project:   lab01_main.cpp
 * Authors: 	Matthew Springer and Matthew Schomacker
 * Date:	    Created on Jan 17, 2017
 * Purpose:	  This program initializes an array and allows for dynamic array modification via user input
 */

#include <iostream>
#include <string>
#include "lab01_methods.h"

using namespace std;

double * v;
int count;
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
    count = 0;
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
            PrintVector();
            break;
        case 2:
            cout << "You selected 'Append element at the end'" << endl;
            AddElement();
            break;
        case 3:
            cout << "You selected 'Remove last element'" << endl;
            RemoveElement();
            break;
        case 4:
            cout << "You selected 'Insert one element'" << endl;
            InsertElement();
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
 * Function:    Grow
 * Input:       None
 * Output:      None
 * Purpose:     Dynamically adjusts the size of the memory allocated for the array
 */
void Grow(){
     if (count == size) {
        int new_size;
        new_size = size *2;
        double* new_v = new double[new_size];
        for (int i = 0; i < count; i++) {
            new_v[i] = v[i];
        }
        delete [] v;
        v = new_v;
        new_v = NULL;
        cout << endl << "Vector grown" << endl;
        cout << "Previous capacity: " << size << " elements" << endl;
        cout << "New capacity: " << new_size << " elements" << endl << endl;
        size = new_size;
     } 
}

/*
 * Function:    PrintVector
 * Input:       None
 * Output:      None
 * Purpose:     Print the current array of elements
 */
void PrintVector(){
     if (count > 0) {
        cout << "Current array: [";
        for (int i = 0; i < count - 1; i++) {
            cout << v[i] << ", ";
        }
        cout << v[count-1] << "]" << endl;
     }
     else {
          cout << "Current array: []" << endl; 
     }
}

/*
 * Function:    AddElement
 * Input:       None
 * Output:      None
 * Purpose:     Append a new element to the end of the array
 */
void AddElement(){
     Grow();
     float new_elem;
     cout << "Enter the new element: ";
     cin >> new_elem;
     v[count] = new_elem;
     count++;
}

/*
 * Function:    RemoveElement
 * Input:       None
 * Output:      None
 * Purpose:     Remove the last element in the array
 */
void RemoveElement(){
     if (count == 0) {
        cout << "Error: there are no elements in the array to remove. Please select another option" << endl;
     }
     else {
          cout << "Deleting element " << v[--count] << " at index " << count << endl;
          Shrink();
     }
}

/*
 * Function:    InsertElement
 * Input:       None
 * Output:      None
 * Purpose:     Insert an element in the array at a specified index
 */
void InsertElement(){
     Grow();
     int insert_index;
     float new_elem;
     cout << "Enter the index for the new element: ";
     cin >> insert_index;
     if (AssertIndexBounds(insert_index)) {
        cout << "Enter the new element: ";
        cin >> new_elem;
        // shift all elements at or above the given index to the right
        for (int i = count-1; i >= insert_index; i--) {
            v[i+1] = v[i];
        }
        v[insert_index] = new_elem;
        count++;
        cout << "Element " << new_elem << " inserted at index " << insert_index << endl;
     }
     else {
          cout << "Error: you have entered an invalid index.  Please enter an index between 0 and " << count << endl;
     }
}

/*
 * Function:    AssertIndexBounds
 * Input:       int index
 * Output:      bool isValid
 * Purpose:     Returns true if the given index is valid for an insertion into the array
 */
bool AssertIndexBounds(int index){
     bool isValid = false;
     if (index >= 0 && index <= count) {
        isValid = true;
     }
     return isValid;
}

/*
 * Function:    Shrink
 * Input:       None
 * Output:      None
 * Purpose:     Reallocates the array with 1/2 its current size when the count falls below 1/3 its
 *              current capacity.  Minimum array size of 2
 */
void Shrink(){
     // if there are no elements and the array is larger than 2, shrink to the default size
     if (count == 0 and size > 2) {
        v = new double[2];
        size = 2;
     }
     else {
          int comparator;
          comparator = count * 3;
          // if the capacity is > 3x the current number of elements in the array, shrink to 1/2 capacity
          // change from (count < 30% size) to (count < 1/3 size) approved by Prof. Kimani
          if (count > 0 and comparator < size) {
             int new_size;
             new_size = size / 2;
             double * new_v = new double[new_size];
             for (int i = 0; i < count; i++) {
                 new_v[i] = v[i];
             }
             delete [] v;
             v = new_v;
             new_v = NULL;
             cout << endl << "Vector shrunk" << endl;
             cout << "Previous capacity: " << size << " elements" << endl;
             cout << "New capacity: " << new_size << " elements" << endl << endl;
             size = new_size;
          }
     }
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
