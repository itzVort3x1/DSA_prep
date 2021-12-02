//------------------------------------
//      Maximum and Minimum element in an array
//      Ex: INPUT: arr={2,5,6,62,35}
//          OUTPUT: max = 62, min = 2
//------------------------------------

#include<iostream>
#include<algorithm>
using namespace std;

int getMax(int arr[], int size){
    int maxi = INT_MIN;

    for(int i=0; i<size; i++){
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int getMin(int arr[], int size){
    int mini = INT_MAX;
    for(int i=0; i<size; i++){
        mini = min(mini, arr[i]);
    }

    return mini;
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