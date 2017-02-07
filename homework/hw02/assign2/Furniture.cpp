#include <iostream>
#include <string>

#include "Furniture.h"

using namespace std;

// constructor
Furniture::Furniture(string nm) {
  name = nm;
}

// destructor
Furniture::~Furniture() {}

/*
 *  Function: readDimensions
 *
 *  Purpose:  initialize width, height, and depth from user input
 */
void Furniture::readDimensions() {
  float w, h, d;
  bool valid = true;
  while (valid) {
    cout << "\t" << "Enter width: ";
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
    cout << "\t" <<  "Enter height: ";
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
    cout << "\t" <<  "Enter depth: ";
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
    valid = false;
  }
}

void Furniture::print() {
  cout << name << ":" << endl;
  cout <<  "\t" << "Width = " << width << ", height = " << height << ", depth = " 
  	<< depth << endl;
}
