// Assignment 6: Compile-time polymorphism using Complex numbers
#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
    int real;
    int image;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        image = i;
    }

    // Function overloading
    void display() const {
        cout << real << " + " << image << "i" << endl;
    }

    void display(string message) const {
        cout << message;
        display();
    }

    // Operator overloading
    Complex operator+(const Complex& c) const {
        Complex temp;
        temp.real = real + c.real;
        temp.image = image + c.image;
        return temp;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(2, 5);

    c1.display();
    c1.display("First Complex Number: ");

    Complex c3 = c1 + c2;

    cout << "Addition: ";
    c3.display();

    return 0;
}
