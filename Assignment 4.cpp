// Assignment 4: Single and multilevel inheritance
// Person -> Student -> GraduateStudent
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void getPersonalDetails() {
        cout << "Enter name: ";
        getline(cin >> ws, name);

        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonalData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int rollNo;
    string course;

public:
    void getStudentDetails() {
        getPersonalDetails();

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Course Name: ";
        getline(cin >> ws, course);
    }

    void displayStudentData() const {
        displayPersonalData();
        cout << "Roll No: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

class GraduateStudent : public Student {
private:
    string specialization;
    int marks;

public:
    void getGraduateStudentDetails() {
        getStudentDetails();

        cout << "Enter Specialization: ";
        getline(cin >> ws, specialization);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayGraduateStudentData() const {
        displayStudentData();
        cout << "Specialization: " << specialization << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 45) {
            cout << "Graduated!" << endl;
        } else {
            cout << "Not Graduated" << endl;
        }
    }
};

int main() {
    GraduateStudent s1;

    s1.getGraduateStudentDetails();

    cout << "\n--- Displaying Details ---" << endl;
    s1.displayGraduateStudentData();

    return 0;
}
