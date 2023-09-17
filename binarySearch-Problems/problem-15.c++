//------------------------------------
//      Find the missing number in the array
//      Ex: INPUT: arr = {1,2,3,4,6,7,8,9}
//          OUTPUT: 5
//          EXPLANATION: As 5 number is not present in the array;
//------------------------------------

#include <iostream>
using namespace std;

int findMissingElement(int arr[], int n)
{

     int start = 0;
     int end = n - 1;
     int mid = start + (end - start) / 2;
     int ans = -1;

     while (start <= end)
     {
          int diff = arr[mid] - mid;
          if (diff == 1)
          {
               start = mid + 1;
          }
          else
          {
               ans = mid;
               end = mid - 1;
          }
          mid = start + (end - start) / 2;
     }

     return ans + 1;
}

int main()
{
     int arr[] = {1, 2, 3, 4, 6, 7, 8, 9};
     int n = 9;

     int missingElement = findMissingElement(arr, n);

     cout << "Missing element is: " << missingElement << endl;

     return 0;
}