/*
 *  Project:    HW #1, Problem # 3
 *  Author:     Matthew Springer
 *  Date:       January 30, 2017
 *  Purpose:    Write a program that produces an array of CarRecords from an
 *              input file and performs operations on the array
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
 */
struct CarRecord {
  string make;
  string model;
  int year;
  string color;
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
 *  @param  record  the CarRecord to populate
 *  @param  line    the line to populate the record from
 *  @return None
 */
void PopulateRecordFromLine(CarRecord * record, string line) {
}

/*
 *  Function: Insert_Array
 *
 *  @param  array     the array of CarRecords to populate
 *  @param  lines    the number of lines in the file
 *  @param  inputFile the name of the file to read from
 *  @return None
 */
void Insert_Array(CarRecord * array, int lines, string inputFile) {
  ifstream myfile;
  string line;
  string make;
  string model;
  string color;
  string yearStr;
  int yearInt;
  myfile.open(inputFile);
  int lineCounter = 0;
  while (!myfile.eof()) {
    for (int i = 0; i < lines; i++) {
      if(getline(myfile, make, ',')){
        //cout << make << " ";
        array[i].make = make;
      }
      if (getline(myfile, model, ',')) {
        //cout << model << " ";
        array[i].model = model;
      }
      if (getline(myfile, yearStr, ',')) {
        //cout << yearStr << " ";
        yearInt = stoi(yearStr);
        array[i].year = yearInt;
      }
      if (getline(myfile, color)) {
        //cout << color << endl;
        array[i].color = color;
      }
    }
  }
}

/*
 *  Function: Sort_Cars_By_Year
 *
 *  @param  array     the array of CarRecords to sort (by year)
 *  @param  legnth    the length of the array
 *  @return None
 */
void Sort_Cars_By_Year(CarRecord * array, int length) {
  int lowestIndex;
  CarRecord * placeholderRecord = new CarRecord;
  for (int i = 0; i < length - 1; i++) {
    lowestIndex = i;
    for (int j = i+1; j < length; j++) {
      if (array[j].year < array[lowestIndex].year) {
        lowestIndex = j;
      }
    }
    if (lowestIndex > i) {
      placeholderRecord->make = array[i].make;
      placeholderRecord->model = array[i].model;
      placeholderRecord->year = array[i].year;
      placeholderRecord->color = array[i].color;
      
      array[i].make = array[lowestIndex].make;
      array[i].model = array[lowestIndex].model;
      array[i].year = array[lowestIndex].year;
      array[i].color = array[lowestIndex].color;
      
      array[lowestIndex].make = placeholderRecord->make;
      array[lowestIndex].model = placeholderRecord->model;
      array[lowestIndex].year = placeholderRecord->year;
      array[lowestIndex].color = placeholderRecord->color;
    }
  }
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
void Print_Cars_Array(CarRecord * array, int length) {
  cout << "Car Records:" << endl << endl;
  string make;
  string model;
  string color;
  int year;
  string space = " ";
  for (int i = 0; i < length; i++) {
    int recordNum = i+1;
    make = array[i].make;
    model = array[i].model;
    year = array[i].year;
    color = array[i].color;
    
    cout << recordNum << ".\t";
    cout << make << space;
    cout << model << space;
    cout << year << space;
    cout << color << endl;
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
  CarRecord * recordsArray = new CarRecord[numRecords];
  bool executing = true;
  while (executing) {
    char input;
    Print_Main_Menu();
    cin >> input;
    cout << endl;
    switch (input) {
      case '1':
        Print_Cars_Array(recordsArray, numRecords);
        break;
      case '2':
        Insert_Array(recordsArray, numRecords, file_name);
        break;
      case '3':
        Sort_Cars_By_Year(recordsArray, numRecords);
        break;
      case '4':
        Print_Duplicates(recordsArray, numRecords);
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
