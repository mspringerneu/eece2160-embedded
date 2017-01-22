#include <iostream> 
#include <string> 

using namespace std;

struct Person {
    string name;
    int age;
};

void PrintPerson(Person *person) {
    cout << person->name << " is " << person->age << " years old" << endl;
}

int main() {
    Person person;
    person.name = "John";
    person.age = 10;
    PrintPerson(&person);
}
