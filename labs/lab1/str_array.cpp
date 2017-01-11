#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

void PrintArray(string v[], int size)
{
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << v[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << "]";
}

void ReadStrings(string v[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << "Please enter string #" << i << ": ";
		cin >> v[i];
	}
}

void RandomArray(int v[], int size)
{
	int value;
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		value = rand() % 100;
		v[i] = value;
	}
	// PrintArray(v, size);
}

void SortStringArray(string v[], int size)
{
	int i, j, index;
	for (int i = 0; i < size-1; i++) {
		index = i;
		for (j = i+1; j < size; j++) {
			if (v[j].compare(v[index]) < 0) {
				index = j;
			}
		}
		
		if (index != i) {
			swap(v[i], v[index]);
		}
	}
}

int main()
{
	string v[10];
	ReadStrings(v, 10);
	cout << "The initial array is: ";
	PrintArray(v, 10);
	cout << endl;
	SortStringArray(v, 10);
	cout << "The sorted array is: ";
	PrintArray(v, 10);
	cout << endl;
	return 0;
}
