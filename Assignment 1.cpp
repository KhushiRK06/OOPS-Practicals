// Assignment 1: Data types, constants, variables, operators and I/O
#include <iostream>
using namespace std;

int main() {
    int age;
    float marks;
    char grade;
    bool passed;

    const int totalMarks = 100;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    cout << "Enter your grade: ";
    cin >> grade;

    float percentage = (marks / totalMarks) * 100;

    cout << "\nAge: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    if (percentage >= 40) {
        passed = true;
    } else {
        passed = false;
    }

    cout << "Passed = " << boolalpha << passed << endl;

    return 0;
}
