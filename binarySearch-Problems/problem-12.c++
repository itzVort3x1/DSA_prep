//------------------------------------
//      First occurance using binary search
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 2 7
//          EXPLANATION: 3 occurs first at index 2 and last occurance of 3 is index 7.
//------------------------------------

#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int target)
{
     int start = 0;
     int end = n - 1;
     int mid = start + (end - start) / 2;
     int ans = -1;

     while (start <= end)
     {
          if (arr[mid] == target)
          {
               ans = mid;
               end = mid - 1;
          }
          else if (target > arr[mid])
          {
               start = mid + 1;
          }
          else if (target < arr[mid])
          {
               end = mid - 1;
          }
          mid = start + (end - start) / 2;
     }

     return ans;
}

int main()
{
     int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 5, 8};
     int target = 5;
     int n = 9;

     int ansIndex = firstOcc(arr, n, target);

     if (ansIndex == -1)
     {
          cout << "Element not found " << endl;
     }
     else
     {
          cout << "First Occ found at: " << ansIndex << endl;
     }

     return 0;
}