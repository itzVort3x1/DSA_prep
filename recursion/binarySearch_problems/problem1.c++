//------------------------------------
//      First and last occurance using binary search
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 2 7
//          EXPLANATION: 3 occurs first at index 2 and last occurance of 3 is index 7.
//------------------------------------

#include <iostream>
using namespace std;

void print(int arr[], int s, int e)
{
     for (int i = s; i < e; i++)
     {
          cout << arr[i] << " ";
     }
}

int firstOc(int arr[], int key, int s, int e)
{
     print(arr, s, e);
     cout << endl;
     int mid = s + (e - s) / 2;
     int ans = -1;
     if (s > e)
     {
          return ans;
     }
     if (arr[mid] == key)
     {
          ans = mid;
          firstOc(arr, key, s, mid - 1);
     }
     if (arr[mid] < key)
     {
          firstOc(arr, key, s, mid - 1);
     }
     else
     {
          firstOc(arr, key, mid + 1, e);
     }
     return ans;
}

int firstOcc(int arr[], int key, int n)
{
     int s = 0, e = n - 1;
     int mid = s + (e - s) / 2;

     int ans = -1;

     while (s <= e)
     {
          if (arr[mid] == key)
          {
               ans = mid;
               e = mid - 1;
          }
          else if (key > arr[mid])
          {
               s = mid + 1;
          }
          else if (key < arr[mid])
          {
               e = mid - 1;
          }
          mid = s + (e - s) / 2;
     }

     return ans;
}

int lastOcc(int arr[], int key, int n)
{
     int s = 0, e = n - 1;
     int mid = s + (e - s) / 2;

     int ans = -1;

     while (s <= e)
     {
          if (arr[mid] == key)
          {
               ans = mid;
               s = mid + 1;
          }
          else if (key > arr[mid])
          {
               s = mid + 1;
          }
          else if (key < arr[mid])
          {
               e = mid - 1;
          }
          mid = s + (e - s) / 2;
     }

     return ans;
}

int main()
{
     int arr[10] = {1, 2, 3, 3, 3, 3, 3, 3, 5, 8};
     firstOc(arr, 3, 0, 9);
     // cout << "First occurance of 3 is: " << firstOc(arr, 3, 0, 9) << endl;
     cout
         << "Last occurance of 3 is: " << lastOcc(arr, 3, 10);

     return 0;
}