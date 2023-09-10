#include <iostream>
using namespace std;

float areaOfCircle(float radius)
{
     return 3.14 * radius * radius;
}

int main()
{
     float radius;
     cin >> radius;

     float area = areaOfCircle(radius);

     cout << "Area of circle: " << area;
}