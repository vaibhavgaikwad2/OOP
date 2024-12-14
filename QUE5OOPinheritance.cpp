#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Vehicle {
protected:
    string model;
    float speed;

public:
    // Function to input Vehicle details
    void input() {
        cout << "Enter Model: ";
        cin.ignore();
        getline(cin, model);

        cout << "Enter Speed (in km/h): ";
        cin >> speed;

        // Exception handling for invalid speed
        if (speed < 0 || speed > 300) {
            throw invalid_argument("Speed must be between 0 and 300 km/h!");
        }
    }

    // Function to display Vehicle details
    void display() const {
        cout << "Model: " << model << "\nSpeed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
    string fuelType;

public:
    // Function to input Car details
    void input() {
        Vehicle::input();

        cout << "Enter Fuel Type (Petrol/Diesel): ";
        cin >> fuelType;

        // Exception handling for invalid fuel type
        if (fuelType != "Petrol" && fuelType != "Diesel") {
            throw invalid_argument("Invalid fuel type! Must be Petrol or Diesel.");
        }
    }

    // Function to display Car details
    void display() const {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

int main() {
    Car car;

    try {
        cout << "Enter details for the Car:\n";
        car.input();

        cout << "\n--- Car Details ---\n";
        car.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

