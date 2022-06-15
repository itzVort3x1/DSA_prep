#include <iostream>
using namespace std;

void printCounting(int n)
{
     // base case
     if (n == 0)
     {
          return;
     }

     // recursive relation
     cout << n << endl;
     printCounting(n - 1);
}

int main()
{
     int n;
     cin >> n;
     cout << endl;
     printCounting(n);

     return 0;
}