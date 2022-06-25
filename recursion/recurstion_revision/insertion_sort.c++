#include <iostream>
using namespace std;

void print(int *arr)
{
     for (int i = 0; i < 7; i++)
     {
          cout << arr[i] << " ";
     }
     cout << endl;
}

void insertionSort(int *arr, int n)
{

     if (n <= 1)
     {
          return;
     }
     insertionSort(arr, n - 1);
     int last = arr[n - 1];
     int j = n - 2;

     while (j >= 0 && arr[j] > last)
     {
          arr[j + 1] = arr[j];
          j--;
     }
     arr[j + 1] = last;
}

int main()
{
     int arr[7] = {10, 1, 7, 4, 8, 2, 11};

     insertionSort(arr, 7);

     print(arr);
}