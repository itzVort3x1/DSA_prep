// -------------------------
//     1 2 3 4 5
//     1     4
//     1   3
//     1 2
//     1
// -------------------------

#include <iostream>
using namespace std;

int main()
{
     int n;
     cin >> n;

     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j <= n; j++)
          {
               if (j == i + 1 || j == n || i == 0)
               {

                    cout << j;
               }
               else
               {
                    cout << " ";
               }
          }
          cout << endl;
     }
}