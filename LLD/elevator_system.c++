#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum class Direction { UP, DOWN };
enum class RequestType { PICKUP, DESTINATION };
enum class ButtonPlace { INSIDE, OUTSIDE };

class Elevator {
    private:
        int currentFloor;
        Direction direction;
        queue<string> request;
    public:
        Elevator(int currentFloor, Direction direction, string request);

        void move();
        void addRequest(int floor);
        int getCurrentFloor();
        Direction getDirection();
        void openDoor();
        void closeDoor();
        void isIdle();
        void tick();
        void getNextDestination();
};

class ElevatorController {
    private:
        vector<Elevator> elevators;

    public:
         ElevatorController(vector<Elevator> elevators);

        void handleExternalRequest(int floor, Direction direction);

        void handleExternalRequest(int elevatorId, int destinationFloor);

        void step();
};

class Request {
    private:
        RequestType type;
        int floor;
        Direction direction;

    public:
        Request(RequestType type, int floor, Direction direction);
};

class Building {
    private: 
        int numberOfFloors;
        int numberOfElevators;
        ElevatorController controller;
    public:
        Building(int numberOfFloors, int numberOfElevators);

        void requestPickup(int floor, Direction direction);
        void tick();
};

class Button {
    private:
        ButtonPlace place;
        Request request;
    public:
        Button(ButtonPlace place);

        void registerRequest(int floor, RequestType type, Direction direction);
};

int main() {

}