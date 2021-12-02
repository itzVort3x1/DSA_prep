//------------------------------------
//      Maximum and Minimum element in an array
//      Ex: INPUT: arr={2,5,6,62,35}
//          OUTPUT: max = 62, min = 2
//------------------------------------

#include<iostream>
using namespace std;

int getMax(int arr[], int size){
    int max = INT_MIN;

    for(int i=0; i<size; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }

    return max;
}

int getMin(int arr[], int size){
    int min = INT_MAX;

    for(int i=0; i<size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }

    return min;
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int num[100];

    //taking input in array
    for(int i=0; i<size; i++){
        cin>>num[i];
    }

    cout<<"Maximum value is: "<< getMax(num, size) << endl;
    cout<<"Minimum value is: "<< getMin(num, size) << endl;

}