//------------------------------------
//      Print sum of all elements in an array
//      Ex: INPUT: arr={2,5,6,8,12}
//          OUTPUT: 33
//------------------------------------

#include<iostream>
using namespace std;

int main() {
    int arr[5] = {2,5,6,8,12};

    int sum=0;
    for(int i=0; i<5; i++){
        sum += arr[i];
    }

    cout<<"Sum of the elements in the array is: "<<sum<<endl;
}