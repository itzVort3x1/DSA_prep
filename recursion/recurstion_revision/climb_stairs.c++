#include <iostream>
using namespace std;

int calculateTheWays(int dest)
{
     if (dest < 0)
     {
          return 0;
     }
     if (dest == 0)
     {
          return 1;
     }
     return calculateTheWays(dest - 1) + calculateTheWays(dest - 2);
}

int main()
{
     int dest;
     cin >> dest;

     int result = calculateTheWays(dest);

     cout << "The number of ways are: " << result << endl;
}