#include <iostream>
using namespace std;

// State interface
class FanState {
public:
    virtual void handlePress() = 0;
    virtual ~FanState() {}
};

// Concrete states
class OffState : public FanState {
public:
    void handlePress() override {
        cout << "Fan is OFF → Turning to LOW speed" << endl;
    }
};

class LowState : public FanState {
public:
    void handlePress() override {
        cout << "Fan is on LOW speed → Turning to HIGH speed" << endl;
    }
};

class HighState : public FanState {
public:
    void handlePress() override {
        cout << "Fan is on HIGH speed → Turning OFF" << endl;
    }
};

// Context
class Fan {
private:
    FanState* state; // current state

public:
    Fan(FanState* initialState) : state(initialState) {}

    void setState(FanState* newState) {
        state = newState;
    }

    void pressButton() {
        state->handlePress();
    }
};

// Client code
int main() {
    OffState off;
    LowState low;
    HighState high;

    Fan fan(&off);

    fan.pressButton(); // OFF → LOW
    fan.setState(&low);

    fan.pressButton(); // LOW → HIGH
    fan.setState(&high);

    fan.pressButton(); // HIGH → OFF
    fan.setState(&off);

    return 0;
}
