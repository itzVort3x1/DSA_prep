// A subject maintains a list of observers that are notified automatically of any state changes.
// Use case
// 1) Event System
// 2) GUI Frameworks
// 3) Data Monitoring tools
#include <iostream>
#include <vector>
using namespace std;

class Display {
    string name;
public:
    Display(const string& n) : name(n) {}

    void update(int temp) {
        cout << name << " received update: Temperature is " << temp << "°C\n";
    }
};

class WeatherStation {
    vector<Display*> displays;
    int temperature;
    public:
        void attach(Display& d) {
            displays.push_back(&d);
        }

        void setTemperature(int temp) {
            temperature = temp;
            notifyAll();
        }

        void notifyAll() {
            for (auto d : displays) {
                d->update(temperature);
            }
        }
};

int main() {
    WeatherStation station;

    Display d1("Display1");
    Display d2("Display2");

    station.attach(d1);
    station.attach(d2);

    station.setTemperature(30);
    station.setTemperature(35);

    return 0;
}

