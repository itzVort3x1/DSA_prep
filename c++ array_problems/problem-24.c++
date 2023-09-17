//------------------------------------
//      sort 0's, 1's and 2's
//      Ex: INPUT: arr={0,1,0,1,1,0,2,2,0,1,2}
//          OUTPUT: 0,0,0,0,1,1,1,1,2,2,2
//------------------------------------

#include <iostream>
using namespace std;

int main()
{
     int arr[] = {0, 1, 0, 1, 1, 0, 2, 2, 0, 1, 2};
     int n = 11;
     int low = 0;
     int mid = 0;
     int high = n - 1;

     while (mid <= high)
     {
          if (arr[mid] == 1)
          {
               mid++;
          }
          else if (arr[mid] == 0)
          {
               swap(arr[mid], arr[low]);
               low++;
               mid++;
          }
          else
          {
               swap(arr[mid], arr[high]);
               high--;
          }
     }

     cout << "Sorted array is: " << endl;
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }

     cout << endl;
}