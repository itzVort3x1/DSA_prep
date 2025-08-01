#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

enum class DIRECTIONS {NORTH, SOUTH, EAST, WEST};
enum class COLOR {RED, YELLOW, GREEN};

class TrafficController {
private:
    unordered_map<string, IntersectionController> intersections;  // e.g., "5th&Main" → controller

public:
    // Adds a new intersection to the system
    void addIntersection(const string& intersectionId, const IntersectionController& controller);

    // Ticks all intersections (e.g., every second)
    void tickAll();

    // Cycles lights at a specific intersection
    void cycleIntersection(const string& intersectionId);

    // Overrides a specific light at a specific intersection
    void overrideIntersectionLight(const string& intersectionId, DIRECTIONS dir, COLOR newColor);

    // Gets the global snapshot of traffic light states
    unordered_map<string, unordered_map<DIRECTIONS, COLOR>> getSystemState() const;
};

class IntersectionController {
    private:
        unordered_map<DIRECTIONS, TrafficLight> trafficLights;
    
    public:
        IntersectionController() {
            trafficLights[DIRECTIONS::NORTH] = TrafficLight(DIRECTIONS::NORTH, COLOR::RED, 0);
            trafficLights[DIRECTIONS::SOUTH] = TrafficLight(DIRECTIONS::SOUTH, COLOR::RED, 0);
            trafficLights[DIRECTIONS::EAST] = TrafficLight(DIRECTIONS::EAST, COLOR::GREEN, 0);
            trafficLights[DIRECTIONS::WEST] = TrafficLight(DIRECTIONS::WEST, COLOR::GREEN, 0);
        }

        void cycleLights();
        void tick();
        unordered_map<DIRECTIONS, COLOR> getStateOfAllLights() const;
        void overrideLight(DIRECTIONS dir, COLOR newColor);
};

class TrafficLight {
    private:
        DIRECTIONS direction;
        COLOR signalColor;
        int time;
    public:
        TrafficLight(DIRECTIONS direction, COLOR color, int time) {};

        void changeColor(COLOR newColor);
        COLOR getCurrentColor() const;
        void tick();
};


int main() {
    return 0;
}