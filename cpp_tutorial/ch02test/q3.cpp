#include <iostream>

void compute(double a, double b, char c) {
    using namespace std;
    double x;
    if (c == '+') {
        x = a + b;
        cout << "The computed value is: " << x << endl;
    }
    else if (c == '-') {
        x = a - b;
        cout << "The computed value is: " << x << endl;
    }
    else if (c == '*') {
        x = a * b;
        cout << "The computed value is: " << x << endl;
    }
    else if (c == '/') {
        x = a / b;
        cout << "The computed value is: " << x << endl;
    }
    else {
        cout << "Invalid operator entered.  Exiting..." << endl;
    }
}

void readInputs() {
    using namespace std;
    double a, b;
    char c;
    cout << "Please enter a double: ";
    cin >> a;
    cout << "Please enter another double: ";
    cin >> b;
    cout << "Please enter an operator: ";
    cin >> c;
    compute(a, b, c);
}

int main() {
    readInputs();
	return 0;
}
