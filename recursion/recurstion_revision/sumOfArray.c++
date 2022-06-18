#include <iostream>
using namespace std;

int calculateSumOfArray(int arr[], int size)
{
     int sum = 0;
     if (size == 0)
     {
          return 0;
     }
     if (size == 1)
     {
          return arr[0];
     }
     return arr[0] + calculateSumOfArray(arr + 1, size - 1);
}

int main()
{
     int arr[5] = {3, 2, 5, 1, 6};
     int size = 5;

     int res = calculateSumOfArray(arr, size);

     cout << "The sum of the array is: " << res;
     cout << endl;

     return 0;
}