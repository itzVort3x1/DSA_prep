//------------------------------------
//      Find the Pivot element
//      Ex: INPUT: arr={12,14,16,2,4,6,8,10}
//          OUTPUT: 2
//------------------------------------

#include <iostream>
using namespace std;

int findPivot(int arr[], int n)
{
     int start = 0;
     int end = n - 1;
     int mid = start + (end - start) / 2;

     while (start <= end)
     {
          if (start == end)
          {
               return start;
          }

          if (arr[mid] > arr[mid - 1])
          {
               return mid;
          }
          else if (arr[mid] < arr[mid - 1])
          {
               return mid - 1;
          }
          else if (arr[start] > arr[mid])
          {
               end = mid - 1;
          }
          else
          {
               start = mid + 1;
          }
          mid = start + (end - start) / 2;
     }

     return -1;
}

int main()
{
     int arr[] = {12, 14, 16, 2, 4, 6, 8, 10};
     int n = 8;

     int ans = findPivot(arr, n);

     cout << "The pivot index is: " << ans << endl;
}