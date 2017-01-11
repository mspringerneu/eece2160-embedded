#include <iostream>

int readNumber() {
    using namespace std;
    int a;
    cout << "Please enter an integer:" << endl;
    cin >> a;
    return a;
}

void writeAnswer(int a) {
    using namespace std;
    cout << "The sum of the two numbers is: " << a << endl;
}
