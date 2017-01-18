/*
 * Project: lab01_main.cpp
 * Author: 	Matthew Springer
 * Date:	Created on Jan 17, 2017
 * Purpose:	Header file for methods to be implemented in lab01_main.cpp
 */

/*
 * Function:    Initialize
 * Input:       None
 * Output:      None
 * Purpose:     Initializes an empty array of size 2
 */
void Initialize();

/*
 * Function:    Finalize
 * Input:       None
 * Output:      None
 * Purpose:     Deletes the dynamically allocated global variables
 */
void Finalize();

/*
 * Function:    PrintMainMenu
 * Input:       None
 * Output:      None
 * Purpose:     Print's the main program's menu, detailing user modifications
 */
void PrintMainMenu();

/*
 * Function:    ReadUserInput
 * Input:       None
 * Output:      Int x: the number input by the user
 * Purpose:     Read's user's input and calls the appropriate function, or re-displays the menu
 *              if an invalid input is given
 */
void ReadUserInput();

/*
 * Function:    HandleUserInput
 * Input:       None
 * Output:      None
 * Purpose:     Calls the appropriate function based on the user input, or re-displays the menu
 *              if an invalid input is given
 */
void HandleUserInput();

/*
 * Function:    Grow
 * Input:       None
 * Output:      None
 * Purpose:     Dynamically adjusts the size of the memory allocated for the array
 */
void Grow();

/*
 * Function:    PrintVector
 * Input:       None
 * Output:      None
 * Purpose:     Print the current array of elements
 */
void PrintVector();

/*
 * Function:    AddElement
 * Input:       None
 * Output:      None
 * Purpose:     Append a new element to the end of the array
 */
void AddElement();

/*
 * Function:    RemoveElement
 * Input:       None
 * Output:      None
 * Purpose:     Remove the last element in the array
 */
void RemoveElement();

/*
 * Function:    InsertElement
 * Input:       None
 * Output:      None
 * Purpose:     Insert an element in the array at a specified index
 */
void InsertElement();

/*
 * Function:    AssertIndexBounds
 * Input:       int index
 * Output:      bool isValid
 * Purpose:     Helper function for InsertElement().  Returns true if the given index is valid for 
 *              an insertion into the array
 */
bool AssertIndexBounds(int index);

/*
 * Function:    Shrink
 * Input:       None
 * Output:      None
 * Purpose:     Reallocates the array with 1/2 its current size when the count falls below 1/3 its
 *              current capacity.  Minimum array size of 2
 */
void Shrink();

