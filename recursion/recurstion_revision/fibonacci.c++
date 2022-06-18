#include <iostream>
using namespace std;

int nthFibTerm(int n)
{
     if (n == 0)
     {
          return 0;
     }
     if (n == 1)
     {
          return 1;
     }
     return nthFibTerm(n - 1) + nthFibTerm(n - 2);
}

int main()
{
     int n;
     cin >> n;

     int result = nthFibTerm(n);

     cout << "Nth fibonnaci term is: " << result << endl;
}