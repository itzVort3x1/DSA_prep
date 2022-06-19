#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
     if (size == 0)
     {
          return false;
     }

     if (arr[0] == key)
     {
          return true;
     }

     return linearSearch(arr + 1, size - 1, key);
}

int main()
{
     int arr[5] = {3, 5, 1, 2, 6};

     bool index = linearSearch(arr, 5, 6);

     if (index)
     {
          cout << "Element found in the array" << endl;
     }
     else
     {
          cout << "Element not found" << endl;
     }
}