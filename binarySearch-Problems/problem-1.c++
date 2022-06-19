//------------------------------------
//      First and last occurance using binary search
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 2 7
//          EXPLANATION: 3 occurs first at index 2 and last occurance of 3 is index 7.
//------------------------------------

#include <iostream>
using namespace std;

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

    cout << "First occurance of 3 is: " << firstOcc(arr, 3, 10) << endl;
    cout << "Last occurance of 3 is: " << lastOcc(arr, 3, 10);

    return 0;
}