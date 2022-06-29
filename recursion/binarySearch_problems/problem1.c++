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

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int last(int arr[], int low, int high, int x, int n){
     if(high >= low){
          int mid = low + (high - low)/2;
          if((mid == n-1 || x < arr[mid + 1]) && arr[mid] == x){
               return mid;
          }else if(x < arr[mid]){
               return last(arr, low, (mid - 1), x, n);
          }else {
               return last(arr, (mid + 1), high, x, n);
          }
     }
     return -1;
}

int main()
{
     int arr[10] = {1, 2, 3, 3, 3, 3, 3, 3, 5, 8};
     int n = sizeof(arr) / sizeof(int);
     // first(arr, 0, 9, 3, n);
     cout << "First occurance of 3 is: " << first(arr, 0, 9, 3, n) << endl;
     cout << "Last occurance of 3 is: " << last(arr, 0, 9, 3, n) << endl;

     return 0;
}