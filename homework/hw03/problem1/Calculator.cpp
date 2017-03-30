/*
 *  Project:  HW03 Problem #1
 *  File:     Calculator.cpp
 *  Author:   Matthew Springer
 *  Date:     12 March, 2017
 */

template<class T>
Calculator<T>::Calculator() {
  this->value1 = new T;
  this->value2 = new T;
}
  
template<class T>
Calculator<T>::Calculator(T value1, T value2) {
  this->value1 = value1;
  this->value2 = value2;
}
  
template<class T>
T Calculator<T>::getValue1() {
  return this->value1;
}
  
template<class T>
T Calculator<T>::getValue2() {
  return this->value2;
}
  
template<class T>
T Calculator<T>::getSum() {
  return this->value1 + this->value2;
}

template<class T>
int Calculator<T>::getLogicalAND() {
  return this->value1 && this->value2;
}
  
template<class T>
bool Calculator<T>::isGreater() {
  return this->value1 > this->value2;
}
