/*
 *  Project:  HW03 Problem #1
 *  File:     CalcMain.cpp
 *  Author:   Matthew Springer
 *  Date:     12 March, 2017
 */

#include <iostream>
#include <string>
#include "Calculator.h"

class Arithmetic {
private:
  int intData;
  float floatData;
  double doubleData;
  
  template<class T2>
  void printOperations(T2 obj);
  
public:
  Arithmetic();
  Arithmetic(int i, float f, double d);
  void intOperations(Arithmetic obj);
  void floatOperations(Arithmetic obj);
  void doubleOperations(Arithmetic obj);
};

Arithmetic::Arithmetic() {
  intData = 0;
  floatData = 0.0f;
  doubleData = 0.0;
}

Arithmetic::Arithmetic(int i, float f, double d) {
  intData = i;
  floatData = f;
  doubleData = d;
}



int main()
{
  // Create 1st object
  int int1 = 4;
  float f1 = 10.4;
  double d1 = 20.1;
  Arithmetic object1(int1, f1, d1);
  // Create 2nd object
  int int2 = 7;
  float f2 = 0.0;
  double d2 = 3.5;
  Arithmetic object2(int2, f2, d2);
  // Check operation on integer data type
  cout << "\nPrinting INTEGER operations..." << endl;
  object1.intOperations(object2);
  // Check operation on float data type
  cout << "\nPrinting FLOAT operations..." << endl;
  object1.floatOperations(object2);
  // Check operation on double data type
  cout << "\nPrinting DOUBLE operations..." << endl;
  object1.doubleOperations(object2);
} 
// end main
