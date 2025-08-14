// Define an interface for creating objects, but let subclasses decide which class to instantiate.
// Use case
// 1) When object creation needs to be abstracted from the client code.
// 2) Ex: Shapes, Transport modes, UI Elements.
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Car {
public:
    void drive() {
        cout << "Driving a Car\n";
    }
};

class Bike {
public:
    void drive() {
        cout << "Riding a Bike\n";
    }
};

class VehicleFactory {
public:
    static void createAndDriveVehicle(const string& type) {
        if (type == "car") {
            Car car;
            car.drive();
        } else if (type == "bike") {
            Bike bike;
            bike.drive();
        } else {
            cout << "Unknown vehicle type\n";
        }
    }
};

int main() {
    VehicleFactory::createAndDriveVehicle("car");
    VehicleFactory::createAndDriveVehicle("bike");
    VehicleFactory::createAndDriveVehicle("plane"); // Example of unknown

    return 0;
}
