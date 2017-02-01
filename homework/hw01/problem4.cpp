/*
 *  Project:    HW #1, Problem # 4
 *  Author:     Matthew Springer
 *  Date:       January 30, 2017
 *  Purpose:    Write a program that produces a linked list of CarRecords from an
 *              input file and performs operations on the linked list
 */

// Libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 *  Struct Name:  CarRecord
 *
 *  @param  make  the make of the car
 *  @param  model the model of the car
 *  @param  year  the year of the car
 *  @param  color the color of the car
 *  @param  next  pointer to the next node in the linked list
 */
struct CarRecord {
  string make;
  string model;
  int year;
  string color;
  CarRecord * next;
};

/*
 *  Function: LinesInFile
 *
 *  @param  file_name the name of the file to read from
 *  @return int       the number of lines in the file
 */
int LinesInFile(string file_name) {
  ifstream myfile;
  string line;
  int numLines = 0;
  myfile.open(file_name);
  while (getline(myfile, line))
    numLines++;
  return numLines;
}

/*
 *  Function: PopulateRecordFromLine
 *
 *  @param  record  pointer to the head of the CarRecord linkedList to populate
 *  @param  line    the line to populate the record from
 *  @return None
 */
void PopulateRecordFromLine(CarRecord * record, string line) {
}

/*
 *  Function: Insert_LinkedList
 *
 *  @param  head      the first node in the linked list of CarRecords to populate
 *  @param  tail      the last node in the linked list of CarRecords to populate
 *  @param  lines     the number of lines in the file
 *  @param  inputFile the name of the file to read from
 *  @return None
 */
CarRecord * Initialize_Linked_List(int length) {
  CarRecord * head = new CarRecord;
  head->next = NULL;
  CarRecord * currentNode = head;
  for (int i = 1; i < length; i++) {
    CarRecord * newNode = new CarRecord;
    newNode->next = NULL;
    currentNode->next = newNode;
    currentNode = currentNode->next;
  }
  return head;
}

/*
 *  Function: Insert_LinkedList
 *
 *  @param  head      the first node in the linked list of CarRecords to populate
 *  @param  tail      the last node in the linked list of CarRecords to populate
 *  @param  lines     the number of lines in the file
 *  @param  inputFile the name of the file to read from
 *  @return None
 */
void Insert_LinkedList(CarRecord * head, int lines, string inputFile) {
  ifstream myfile;
  string line;
  string make;
  string model;
  string color;
  string yearStr;
  int yearInt;
  
  CarRecord * tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  
  myfile.open(inputFile);
  int lineCounter = 0;
  CarRecord * currentNode = head;
  while (!myfile.eof()) {
    for (int i = 0; i < lines; i++) {
      if(getline(myfile, make, ',')){
        //cout << make << " ";
        currentNode->make = make;
      }
      if (getline(myfile, model, ',')) {
        //cout << model << " ";
        currentNode->model = model;
      }
      if (getline(myfile, yearStr, ',')) {
        //cout << yearStr << " ";
        yearInt = stoi(yearStr);
        currentNode->year = yearInt;
      }
      if (getline(myfile, color)) {
        //cout << color << endl;
        currentNode->color = color;
      }
      
      currentNode = currentNode->next;
      
    }
  }
}

/*
 *  Function: Sort_Cars_By_Year
 *
 *  @param  head      the first node in the linked list of CarRecords to sort (by color)
 *  @param  tail      the last node in the linked list of CarRecords to sort (by color)
 *  @param  legnth    the length of the array
 *  @return None
 */
void Sort_Cars_By_Color(CarRecord * head, int length) {
  CarRecord * currentLeftNode = head;
  CarRecord * currentRightNode = head;
  CarRecord * lowestNode = head;
  CarRecord * tempNode = new CarRecord;
  bool unsorted = true;
  for (int i = 0; i < length - 1; i++) {
    lowestNode = currentLeftNode;
    currentRightNode = currentLeftNode->next;
    while (currentRightNode != NULL) {
      if ((lowestNode->color).compare(currentRightNode->color) > 0) {
        lowestNode = currentRightNode;
      }
      currentRightNode = currentRightNode->next;
    }
    if (currentLeftNode != lowestNode) {
      tempNode->make = currentLeftNode->make;
      tempNode->model = currentLeftNode->model;
      tempNode->year = currentLeftNode->year;
      tempNode->color = currentLeftNode->color;
      
      currentLeftNode->make = lowestNode->make;
      currentLeftNode->model = lowestNode->model;
      currentLeftNode->year = lowestNode->year;
      currentLeftNode->color = lowestNode->color;
      
      currentRightNode->make = tempNode->make;
      currentRightNode->model = tempNode->model;
      currentRightNode->year = tempNode->year;
      currentRightNode->color = tempNode->color;
    }
    currentLeftNode = currentLeftNode->next;
  }
  delete tempNode;
}

/*
 *  Function: Print_Duplicates
 *
 *  @param  array     the array of CarRecords to scan for duplicates to print
 *  @param  legnth    the length of the array
 *  @return None
 */
void Print_Duplicates(CarRecord * array, int length) {
  bool hasDupes = false;
  bool * duplicates = new bool[length];
  for (int i = 0; i < length - 1; i++) {
    for (int j = i+1; j < length; j++) {
      if (array[i].make == array[j].make &&
          array[i].model == array[j].model &&
          array[i].year == array[j].year &&
          array[i].color == array[j].color) {
        duplicates[i] = true;
        duplicates[j] = true;
        hasDupes = true;
      }
    }
  }
  if (hasDupes) {
    cout << "Duplicate Entries: " << endl << endl;
    for (int i = 0; i < length - 1; i++) {
      if (duplicates[i]) {
        cout << i+1 << ".\t";
        cout << array[i].make << " ";
        cout << array[i].model << " ";
        cout << array[i].year << " ";
        cout << array[i].color << endl;
      }
    }
    cout << endl;
  }
  else cout << "No duplicate entries" << endl << endl;
}

/*
 *  Function: Print_Cars_Array
 *
 *  @param  array     the array of CarRecords to print
 *  @param  legnth    the length of the array
 *  @return None
 */
void Print_Cars_List(CarRecord * head, int length) {
  cout << "Car Records:" << endl << endl;
  string make;
  string model;
  string color;
  int year;
  string space = " ";
  CarRecord * currentNode = head;
  for (int i = 0; i < length; i++) {
    int recordNum = i+1;
    make = currentNode->make;
    model = currentNode->model;
    year = currentNode->year;
    color = currentNode->color;
    
    cout << recordNum << ".\t";
    cout << make << space;
    cout << model << space;
    cout << year << space;
    cout << color << endl;
    
    currentNode = currentNode->next;
  }
  cout << endl;
}

/*
 *  Function: Print_Main_Menu
 *  MENU - Select an option:
 1. Print the cars array
 2. Insert car records into a sorted array
 3. Sort cars by year
 4. Print duplicates
 5. Exit
 */
void Print_Main_Menu() {
  cout << "MAIN MENU:" << endl << endl;
  cout << "1. Print the cars array" << endl;
  cout << "2. Insert car records into an array" << endl;
  cout << "3. Sort the array by year" << endl;
  cout << "4. Print duplicates" << endl;
  cout << "5. Exit" << endl << endl;
  cout << "Please enter an option from the menu above: ";
}


int main() {
  string file_name = "CarRecords.txt";
  int numRecords = LinesInFile(file_name);
  CarRecord * headNode = Initialize_Linked_List(numRecords);
  bool executing = true;
  while (executing) {
    char input;
    Print_Main_Menu();
    cin >> input;
    cout << endl;
    switch (input) {
      case '1':
        Print_Cars_List(headNode, numRecords);
        break;
      case '2':
        Insert_LinkedList(headNode, numRecords, file_name);
        break;
      case '3':
        Sort_Cars_By_Color(headNode, numRecords);
        break;
      case '4':
        //Print_Duplicates(headNode, numRecords);
        break;
      case '5':
        executing = false;
        break;
      default:
        cout << "You have entered an invalid input.  Please enter the number that corresponds with the command you wish to execute.  Re-displaying main menu..." << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        break;
    }
  }
  return 0;
}
