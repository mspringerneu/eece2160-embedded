/*
 *  Project:    HW #1, Problem # 1
 *  Author:     Matthew Springer
 *  Date:       January 30, 2017
 *  Purpose:    Read two integers from stdin and performs a number of operations on them
 */
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

/*
 *  Function: PrintDataSizes
 *
 *  Purpose:  Prints out the number of bytes used to store various data types
 */
void PrintDataSizes() {
  cout << "A   bool requires 1 bytes of memory" << endl;
  cout << "A   char requires 1 bytes of memory" << endl;
  cout << "A    int requires 4 bytes of memory" << endl;
  cout << "A  float requires 4 bytes of memory" << endl;
  cout << "A double requires 8 bytes of memory" << endl;
}

/*
 *  Function: Power
 *
 *  @param  a int
 *  @param  b int
 *  @return a^b
 */
int Power(int a, int b) {
  return pow(a, b);
}

/*
 *  Function: Maximum
 *
 *  @param  a int
 *  @param  b int
 *  @return max(a, b)
 */
int Maximum(int a, int b) {
  return max(a, b);
}

/*
 *  Function: PrintInts
 *
 *  @param  a int
 *  @param  b int
 *  
 *  Purpose: print two given integers in decimal, binary, hex, and octal form
 */
void PrintInts(int a, int b) {
  bitset<8> a_bin(a);
  bitset<8> b_bin(b);
  cout << "Decimal: " << a << ", " << b << endl;
  cout << "Binary: " << a_bin << ", " << b_bin << endl;
  cout << "Octal: " << oct << a << ", " << oct << b << endl;
  cout << "Hexadecimal: " << hex << a << ", " << hex << b << endl;
}

int main() {
  int x, y;
  PrintDataSizes();
  cout << "Please enter the first integer: ";
  cin >> x;
  cout << "Please enter the second integer: ";
  cin >> y;
  cout << x << "^" << y << " = " << Power(x, y) << endl;
  cout << "Max(" << x << ", " << y << ") = " << Maximum(x, y) << endl;
  PrintInts(x, y);
}
