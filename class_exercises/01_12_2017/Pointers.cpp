#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "x = " << x << endl;
	x = 5;
	cout << "x = " << x << endl;
	int *y;
	cout << "y = " << y << endl;
	y = NULL;
	cout << "y = " << y << endl;
	y = &x;
	cout << "y = " << y << endl;
	cout << "*y = " << *y << endl;
	
	*y = 15;
	cout << "*y = " << *y << endl;


	int z[5] = {12,44,17,22,34};
	int *k;
	k = z;
	cout << "z[0] = " << z[0] << endl;
	cout << "k[0] = " << k[0] << endl;
	cout << "*k = " << *k << endl;
	cout << "*z = " << *z << endl;

	cout << "z[1] = " << z[1] << endl;
  cout << "k[1] = " << k[1] << endl;
  cout << "*(k+1) = " << *(k+1) << endl;
  cout << "*(z+1) = " << *(z+1) << endl;

}

