/*
 * @file	print.cpp
 * @author	Matthew Springer
 * @date	February 13, 2017
 */

#include <iostream>
#include <string>

using namespace std;

template <class T>
void printData(T a, T b) {
	T c = a + b;
	cout << a << " + " << b << " = " << c << endl;
}

int main() {
	printData(3, 4);
	printData(4.33, 1.66);
	string name1 = "John";
	string name2 = " Doe";
	printData(name1, name2);
}
