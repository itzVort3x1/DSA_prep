#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum class VehicleType { Motorcycle, Car, Truck };
enum class SpotType { Motorcycle, Car, Truck };

// =================== VEHICLE =====================
class Vehicle {
protected:
    string licensePlate;
    VehicleType type;
public:
    Vehicle(string plate, VehicleType t)  {
        licensePlate = plate;
        type = t;
    }

    VehicleType getType() const { return type; }
    string getPlate() const { return licensePlate; }
};

// =================== PARKING SPOT =====================
class ParkingSpot {
protected:
    int spotId;
    bool occupied;
    SpotType type;
public:
    ParkingSpot(int id, SpotType t) {
        spotId = id;
        type = t;
        occupied = false;
    }

    bool isOccupied() { return occupied; }
    void parkVehicle() { occupied = true; }
    void removeVehicle() { occupied = false; }
    SpotType getType() { return type; }
    int getId() { return spotId; }
};

// =================== PARKING LEVEL =====================
class ParkingLevel {
protected:
    int levelNumber;
    vector<ParkingSpot> allSpots;
public:
    ParkingLevel(int floor) : levelNumber(floor) {
        int idCounter = 0;
        for (int i = 0; i < 10; i++)
            allSpots.push_back(ParkingSpot(idCounter++, SpotType::Car));
        for (int i = 0; i < 20; i++)
            allSpots.push_back(ParkingSpot(idCounter++, SpotType::Motorcycle));
        for (int i = 0; i < 5; i++)
            allSpots.push_back(ParkingSpot(idCounter++, SpotType::Truck));
    }

    int getLevelNumber() const {
        return levelNumber;
    }

    bool assignSpot(SpotType t) {
        for (auto &spot : allSpots) {
            if (!spot.isOccupied() && spot.getType() == t) {
                spot.parkVehicle();
                cout << "Vehicle parked at Level " << levelNumber << ", Spot ID " << spot.getId() << endl;
                return true;
            }
        }
        return false;
    }

    void printAvailableSpots() {
        int cars = 0, bikes = 0, trucks = 0;
        for (auto &spot : allSpots) {
            if (!spot.isOccupied()) {
                if (spot.getType() == SpotType::Car) cars++;
                else if (spot.getType() == SpotType::Motorcycle) bikes++;
                else if (spot.getType() == SpotType::Truck) trucks++;
            }
        }
        cout << "Level " << levelNumber << ": Available => Car: " << cars
             << ", Bike: " << bikes << ", Truck: " << trucks << endl;
    }
};

// =================== PARKING LOT =====================
class ParkingLot {
protected:
    vector<ParkingLevel> parkingLevels;
public:
    ParkingLot(int floors) {
        for (int i = 0; i < floors; i++) {
            parkingLevels.push_back(ParkingLevel(i + 1));
        }
    }

    void printLevels() const {
        for (const auto &level : parkingLevels) {
            cout << "Initialized level: " << level.getLevelNumber() << endl;
        }
    }

    void getParkingSpotsOnLevel(int level) {
        if (level < 1 || level > parkingLevels.size()) {
            cout << "Invalid level!" << endl;
            return;
        }
        parkingLevels[level - 1].printAvailableSpots();
    }

    void parkVehicleOnFirstAvailableLevel(SpotType type) {
        for (auto &level : parkingLevels) {
            if (level.assignSpot(type))
                return;
        }
        cout << "No available spot for that type." << endl;
    }
};

// =================== MAIN =====================
int main() {
    ParkingLot lot(3);
    lot.printLevels();

    lot.getParkingSpotsOnLevel(1);

    cout << "\n--- Parking a Car ---" << endl;
    lot.parkVehicleOnFirstAvailableLevel(SpotType::Car);

    cout << "\n--- Spot Availability After Parking ---" << endl;
    lot.getParkingSpotsOnLevel(1);

    return 0;
}
