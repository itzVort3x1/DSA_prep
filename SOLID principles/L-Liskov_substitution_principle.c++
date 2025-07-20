#include <iostream>
using namespace std;

// Base class for shapes
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    virtual double area() const {
        return width * height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }
};

// Derived class for squares
class Square : public Rectangle {
public:
    Square(double size) : Rectangle(size, size) {}

    void setWidth(double w) {
        width = height = w; // Ensure both width and height remain the same
    }
};

int main() {
    Rectangle rec(10, 7);
    Square sq(3);

    cout << "Width of the rectangle: " << rec.getWidth() << endl;

    return 0;
}