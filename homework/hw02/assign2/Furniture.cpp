#include <iostream>
#include <string>

#include "Furniture.h"

// constructor
Furniture(string nm) {
  name = nm;
}

// destructor
~Furniture() {}

/*
 *  Function: readDimensions
 *
 *  Purpose:  initialize width, height, and depth from user input
 */
void readDimensions() {
  float w, h, d;
  bool valid = true;
  while (valid) {
    cout << "Enter width: ";
    cin >> w;
    if (w >= 0) {
      width = w;
    }
    else {
      cout << "You have entered a negative number, inputs must be positive."
      << endl;
      valid = false;
      break;
    }
    cout << "Enter height: ";
    cin >> h;
    if (h >= 0) {
      height = h;
    }
    else {
      cout << "You have entered a negative number, inputs must be positive."
      << endl;
      valid = false;
      break;
    }
    cout << "Enter depth: ";
    cin >> d;
    if (d >= 0) {
      depth = d;
    }
    else {
      cout << "You have entered a negative number, inputs must be positive."
      << endl;
      valid = false;
      break;
    }
  }
}

virtual void Print() {
  
}
