// Assignment 2: Class hierarchy using Vehicle and Car
// ElectricCar is not included because the notebook marks it "Not Required".
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int number;

protected:
    string brand;

public:
    void setVehicle() {
        number = 101;
        brand = "Toyota";
    }

    void displayVehicle() const {
        cout << "Vehicle Number: " << number << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
private:
    int seats;

public:
    void setCar() {
        seats = 5;
    }

    void displayCar() const {
        displayVehicle();
        cout << "Number of Seats: " << seats << endl;
    }
};

int main() {
    Car c;

    c.setVehicle();
    c.setCar();

    cout << "Car Details" << endl;
    c.displayCar();

    return 0;
}
