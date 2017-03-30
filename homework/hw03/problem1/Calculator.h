/*
 *  Project:  HW03 Problem #1
 *  File:     Calculator.h
 *  Author:   Matthew Springer
 *  Date:     12 March, 2017
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

template<class T> class Calculator
{
private:
  T value1;
  T value2;
public:
  Calculator();
  
  Calculator(T value1, T value2);
  
  T getValue1();
  
  T getValue2();
  
  T getSum();
  
  int getLogicalAND();
  
  bool isGreater();
};

template<class T>
Student<T>::Student(T value1, T value2) {
  data1 = value1;
  data2 = value2;
}
template<class T>
T Student<T>::getSum() {
  T sum = data1 + data2;
 	return sum;
}

#endif
