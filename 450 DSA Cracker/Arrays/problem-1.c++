//------------------------------------
//      Reverse the array
//      Link: https://www.geeksforgeeks.org/problems/reverse-an-array/1
//------------------------------------

#include <iostream>
using namespace std;

int main() {
    int arr[]= {1, 4, 3, 2, 6, 5};
    int n = 6;

    int i = 0; 
    int j = n - 1;

    while(i <= j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << "Reversed Array: " << endl;
    for(int n:arr){
        cout << n << " ";
    }

    cout << endl;
    return 0;
}

