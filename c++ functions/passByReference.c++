#include <iostream>
using namespace std;

void solve(int &a)
{
     a++;
     cout << "Address of a: " << &a << endl;

     cout << "Printing inside solve function: " << a << endl;
}

int main()
{
     int a = 5;
     solve(a);
     cout << a;
}