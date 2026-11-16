// Assignment 3: Constructors and Rule of Five using a Number class
#include <iostream>
#include <utility>
using namespace std;

class Number {
private:
    int* value;

public:
    // 1. Default constructor
    Number() {
        value = new int(0);
        cout << "Default Constructor" << endl;
    }

    // 2. Parameterized constructor
    Number(int x) {
        value = new int(x);
        cout << "Parameterized Constructor" << endl;
    }

    // 3. Copy constructor (deep copy)
    Number(const Number& n) {
        value = new int(*n.value);
        cout << "Copy Constructor" << endl;
    }

    // 4. Move constructor
    Number(Number&& n) noexcept {
        value = n.value;
        n.value = nullptr;
        cout << "Move Constructor" << endl;
    }

    // 5a. Copy assignment operator
    Number& operator=(const Number& n) {
        if (this != &n) {
            if (value == nullptr) {
                value = new int(*n.value);
            } else {
                *value = *n.value;
            }
        }
        cout << "Copy Assignment" << endl;
        return *this;
    }

    // 5b. Move assignment operator
    Number& operator=(Number&& n) noexcept {
        if (this != &n) {
            delete value;
            value = n.value;
            n.value = nullptr;
        }
        cout << "Move Assignment" << endl;
        return *this;
    }

    void display() const {
        if (value != nullptr) {
            cout << "Value: " << *value << endl;
        } else {
            cout << "Value: empty" << endl;
        }
    }

    // Destructor
    ~Number() {
        delete value;
        cout << "Destructor" << endl;
    }
};

int main() {
    Number n1;
    Number n2(10);
    Number n3 = n2;             // Copy constructor
    Number n4 = Number(20);     // Parameterized constructor (move may be elided)

    n3 = n2;                    // Copy assignment
    n4 = Number(30);            // Move assignment may be used

    cout << "\nDisplaying values:" << endl;
    n1.display();
    n2.display();
    n3.display();
    n4.display();

    return 0;
}

// Linux memory check:
// g++ -std=c++11 -g "Assignment 3.cpp" -o assignment3
// valgrind --leak-check=full ./assignment3
