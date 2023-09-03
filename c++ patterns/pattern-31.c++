// -------------------------
//            1
//          1 2 1
//        1 2 3 2 1
//      1 2 3 4 3 2 1
//    1 2 3 4 5 4 3 2 1
// -------------------------

#include <iostream>
using namespace std;

int main()
{
     int n;
     cin >> n;

     for (int i = 0; i < n; i++)
     {
          int space = n - i - 1;
          while (space)
          {
               cout << " ";
               space--;
          }
          int k = 1;
          for (int j = n - i - 1; j < n; j++)
          {
               cout << k;
               k++;
          }

          k--;
          while (k != 1)
          {
               k--;
               cout << k;
          }
          cout << endl;
     }
}