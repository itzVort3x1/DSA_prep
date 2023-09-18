//------------------------------------
//      Find the missing number
//      Ex: INPUT: arr={9,6,4,2,3,5,7,0,1}
//          OUTPUT: 8
//------------------------------------

#include <iostream>
using namespace std;

int main()
{
     int arr[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
     int sum = 0;
     int n = 9;
     for (int i = 0; i < n; i++)
     {
          sum = sum + arr[i];
     }

     int totalSum = 0;
     for (int i = 0; i <= n; i++)
     {
          totalSum = totalSum + i;
     }
     int ans = totalSum - sum;

     cout << "The missing number is: " << ans << endl;
}