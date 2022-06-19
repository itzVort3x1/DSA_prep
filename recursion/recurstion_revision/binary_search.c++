#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{
     if (start > end)
     {
          return false;
     }
     int mid = start + (end - start) / 2;
     if (arr[mid] == key)
     {
          return true;
     }
     if (arr[mid] < key)
     {
          return binarySearch(arr, mid + 1, end, key);
     }
     else
     {
          return binarySearch(arr, start, mid - 1, key);
     }
}

int main()
{
     int arr[10] = {2, 6, 8, 17, 42, 56, 78, 88, 99, 101};
     int size = 10;
     int start = 0;
     int end = size - 1;

     bool res = binarySearch(arr, start, end, 2);

     if (res)
     {
          cout << "Element Found in the Array" << endl;
     }
     else
     {
          cout << "Element not found in the array" << endl;
     }
}