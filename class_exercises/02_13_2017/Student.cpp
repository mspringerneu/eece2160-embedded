#include <iostream>
#include <string>
using namespace std;

template <class T> class Student
{
private:
	T data1;
	T data2;
public:
	Student() {data1 = T(); data2 = T();}
	Student(T value1, T value2);
	T getSum();
};

template <class T>
Student<T>::Student(T value1, T value2) {
	data1 = value1;
	data2 = value2;
}

template <class T>
T Student<T>::getSum() {
	T sum = data1 + data2;
 	return sum;
}

int main()
{
	// Using int data type
	int a1 = 85;
	int b1 = 72;
	Student<int> myStudent(a1, b1);
	cout << a1 << " + " << b1 << " = " << myStudent.getSum();
	cout << endl;

	// Using float data type
	float a2 = 8.5;
	float b2 = 7.2;
	Student<float> myStudent2(a2, b2);
	cout << a2 << " + " << b2 << " = " << myStudent2.getSum();
	cout << endl;

	// Using string data type
	string a3 = "John";
	string b3 = " Doe";
	Student<string> myStudent3(a3, b3);
	cout << a3 << " + " << b3 << " = " << myStudent3.getSum();
	cout << endl;    	
}
