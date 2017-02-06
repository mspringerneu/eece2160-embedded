/*
 *  Project:    HW #2, Problem #1
 *  Author:     Matthew Springer
 *  Date:       February 4, 2017
 *  Purpose:    Write an object-oriented program that produces an array of 
 *              CarRecords from an input file and performs operations on the 
 *              array
 */

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/*
 *  Class Name:  Car
 *
 *  PRIVATE MEMBERS:
 *  @param  make  the make of the car
 *  @param  model the model of the car
 *  @param  year  the year of the car
 *  @param  color the color of the car
 */
class Car {
  
private:
  string make;
  string model;
  int year;
  string color;
  
public:
  Car() {}
  
  ~Car() {}
  
  void setFields(string mk, string md, int yr, string cl) {
    make = mk;
    model = md;
    year = yr;
    color = cl;
  }
  
  string getMake() {
    return make;
  }
  
  string getModel() {
    return model;
  }
  
  int getYear() {
    return year;
  }
  
  string getColor() {
    return color;
  }
};

/*
 *  Class Name:  CarRecords
 *
 *  PRIVATE MEMBERS:
 *  @param  arraySize size of the array set to the number of records read from 
 *                    the file
 *  @param  infile    input file stream used to read information from a file
 *  @param  filename  filename for infile to open;
 *  @param  lines     number of records in file "filename"
 *  @param  cars      a pointer object (to a dynamically allocated array of 
 *                    objects)
 */
class CarRecords {
  
private:
  int arraySize;
  ifstream infile;
  string filename;
  int lines;
  Car *cars;
  
  /*
   *  Function: insertArray
   *
   *  Purpose:  populate the array of Cars from the file "CarRecords.txt"
   */
  void insertArray() {
    string mk;
    string md;
    string cl;
    string yr;
    int yrInt;
    infile.open(filename);
    for (int i = 0; i < arraySize; i++) {
      if(getline(infile, mk, ',') &&
         getline(infile, md, ',') &&
         getline(infile, yr, ',') &&
         getline(infile, cl)){
        yrInt = stoi(yr);
        cars[i].setFields(mk, md, yrInt, cl);
      }
    }
    infile.close();
  }
  
public:
  
  CarRecords(int size) {
    filename = "CarRecords.txt";
    lines = 10;
    // constrain 0 <= arraySize <= lines in file
    arraySize = max(0, min(size, lines));
    cars = new Car[arraySize];
    insertArray();
  }
  
  ~CarRecords() {
    delete [] cars;
  }
  
  /*
   *  Function: printCarRecords
   *
   *  Purpose:  print the array of Cars to the console
   */
  void printCarRecords() {
    cout << endl << "PRINTING " << arraySize << " RECORDS!" << endl;
    cout << "---------------------" << endl;
    string comma = ", ";
    for (int i = 0; i < arraySize; i++) {
      cout << cars[i].getMake() << comma << cars[i].getModel() << comma <<
        cars[i].getYear() << comma << cars[i].getColor() << endl;
    }
    cout << endl;
  }
  
  /*
   *  Function: sortCarRecordsByMake
   *
   *  Purpose:  sort the array of Cars alphabetically by make
   */
  void sortCarRecordsByMake() {
    cout << "SORTING RECORDS BY MAKE...";
    int lowestIndex;
    Car * placeholder = new Car();
    for (int i = 0; i < arraySize - 1; i++) {
      lowestIndex = i;
      for (int j = i+1; j < arraySize; j++) {
        if (cars[j].getMake().compare(cars[lowestIndex].getMake()) < 0 ) {
          lowestIndex = j;
        }
      }
      if (lowestIndex > i) {
        placeholder->setFields(cars[i].getMake(),
                               cars[i].getModel(),
                               cars[i].getYear(),
                               cars[i].getColor());
        
        cars[i].setFields(cars[lowestIndex].getMake(),
                          cars[lowestIndex].getModel(),
                          cars[lowestIndex].getYear(),
                          cars[lowestIndex].getColor());
        
        cars[lowestIndex].setFields(placeholder->getMake(),
                                    placeholder->getModel(),
                                    placeholder->getYear(),
                                    placeholder->getColor());
      }
    }
    delete placeholder;
    cout << "DONE" << endl;
  }
  
  /*
   *  Function: sortCarRecordsByYear
   *
   *  Purpose:  sort the array of Cars by year from lowest->highest
   */
  void sortCarRecordsByYear() {
    cout << "SORTING RECORDS BY YEAR...";
    int lowestIndex;
    Car * placeholder = new Car();
    for (int i = 0; i < arraySize - 1; i++) {
      lowestIndex = i;
      for (int j = i+1; j < arraySize; j++) {
        if (cars[j].getYear() < cars[lowestIndex].getYear()) {
          lowestIndex = j;
        }
      }
      if (lowestIndex > i) {
        placeholder->setFields(cars[i].getMake(),
                               cars[i].getModel(),
                               cars[i].getYear(),
                               cars[i].getColor());
        
        cars[i].setFields(cars[lowestIndex].getMake(),
                          cars[lowestIndex].getModel(),
                          cars[lowestIndex].getYear(),
                          cars[lowestIndex].getColor());
        
        cars[lowestIndex].setFields(placeholder->getMake(),
                                    placeholder->getModel(),
                                    placeholder->getYear(),
                                    placeholder->getColor());
      }
    }
    delete placeholder;
    cout << "DONE" << endl;
  }
  
  /*
   *  Function: printDuplicates
   *
   *  Purpose:  print any duplicate Cars in the array
   */
  void printDuplicates() {
    cout << "CHECKING FOR DUPLICATES...";
    bool hasDupes = false;
    // initialize an array of equal length (in case all records are duplicates)
    bool * duplicates = new bool[arraySize];
    for (int i = 0; i < arraySize - 1; i++) {
      for (int j = i+1; j < arraySize; j++) {
        if (cars[i].getMake() == cars[j].getMake() &&
            cars[i].getModel() == cars[j].getModel() &&
            cars[i].getYear() == cars[j].getYear() &&
            cars[i].getColor() == cars[j].getColor()) {
          duplicates[i] = true;
          duplicates[j] = true;
          hasDupes = true;
        }
      }
    }
    cout << "DONE" << endl << endl;
    if (hasDupes) {
      string comma = ", ";
      for (int i = 0; i < arraySize; i++) {
        if (duplicates[i]) {
          cout << cars[i].getMake() << comma << cars[i].getModel() << comma <<
            cars[i].getYear() << comma << cars[i].getColor() << endl;
        }
      }
      cout << endl;
    }
    else cout << "NO DUPLICATE ENTRIES" << endl << endl;
  }
  
};

int main() {
  int numRecs;
  cout << "Number or Records to read? " ;
  cin >> numRecs;
  CarRecords *cr = new CarRecords(numRecs);
  // Print car records
  cr->printCarRecords();
  // Sort by Year
  cr->sortCarRecordsByYear();
  // Print car records
  cr->printCarRecords();
  // Sort by Make
  cr->sortCarRecordsByMake();
  // Print car records
  cr->printCarRecords();
  // Check for Duplicates
  cr->printDuplicates();
  delete cr;
} // end main
