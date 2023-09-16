//------------------------------------
//      Find total occurances of a number
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 6
//          EXPLANATION: 3 is present 6 times in the array
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

int lastOcc(int arr[], int n, int target)
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
               start = mid + 1;
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
     int target = 3;
     int n = 9;

     int firstIndex = firstOcc(arr, n, target);
     int lastIndex = lastOcc(arr, n, target);

     cout << "Count of the number is: " << lastIndex - firstIndex + 1 << endl;

     return 0;
}