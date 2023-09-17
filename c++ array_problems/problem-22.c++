//------------------------------------
//      Key Pair
//      N = 6, X = 16
//      Arr[] = {1, 4, 45, 6, 10, 8}
//      Output: Yes
//      Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
//------------------------------------

#include <iostream>
using namespace std;

bool twoSumKeyPair(int arr[], int n, int x)
{
     int low = 0;
     int high = n - 1;

     while (low < high)
     {
          int sum = arr[low] + arr[high];
          if (sum == x)
          {
               return true;
          }
          else if (sum > x)
          {
               high--;
          }
          else if (sum < x)
          {
               low++;
          }
     }

     return false;
}

int main()
{
     int arr[] = {1, 4, 45, 6, 10, 8};
     int n = 6;

     sort(arr, arr + n);
     bool ans = twoSumKeyPair(arr, n, 16);

     if (ans)
     {
          cout << "Key pair sum exists" << endl;
     }
     else
     {
          cout << "Key pair sum does not exists" << endl;
     }
}