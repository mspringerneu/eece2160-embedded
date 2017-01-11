#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void PrintArray(int v[], int size)
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

void SortArray(int v[], int size)
{
	int i, j, index;
	for (int i = 0; i < size-1; i++) {
		index = i;
		for (j = i+1; j < size; j++) {
			if (v[j] < v[index]) {
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
	int v[10];
	RandomArray(v, 10);
	cout << "The initial array is: ";
	PrintArray(v, 10);
	cout << endl;
	SortArray(v, 10);
	cout << "The sorted array is: ";
	PrintArray(v, 10);
	cout << endl;
	return 0;
}
