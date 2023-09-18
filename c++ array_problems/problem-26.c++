//------------------------------------
//      Find the duplicate number
//      Ex: INPUT: arr={1,3,4,2,2}
//          OUTPUT: 2
//------------------------------------

#include <iostream>
using namespace std;

int main()
{
     int arr[] = {1, 3, 4, 2, 2};
     int n = 5;
     int ans = -1;
     for (int i = 0; i < n; i++)
     {
          int index = abs(arr[i]);

          if (arr[index] < 0)
          {
               ans = index;
          }

          arr[index] *= -1;
     }

     cout << "The Duplicate number is: " << ans << endl;
}