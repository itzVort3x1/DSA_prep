#include<iostream>
using namespace std;

void heapify(int *arr, int n, int index){
     int leftIndex = 2*index;
     int rightIndex = 2*index + 1;
     int largestKaIndex = index;

     if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
          largestKaIndex = leftIndex;
     }

     if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
          largestKaIndex = rightIndex;
     }

     if(index != largestKaIndex){
          swap(arr[index], arr[largestKaIndex]);
          index = largestKaIndex;
          heapify(arr, n, index);
     }
}

void buildHeap(int arr[], int n){
     // Why n/2? coz n/2+1 is index of leaf nodes and no need to process leaf nodes.
     for(int index = n/2; index>0; index--){
          heapify(arr, n, index);
     }
}

void heapSort(int arr[], int n){
     while(n != 1){
          swap(arr[1], arr[n]);
          n--;
          heapify(arr, n, 1);
     }
}

int main() {
    int arr[] = {-1, 5,10,15,20,25,12};
    int n = 5;
    buildHeap(arr, 6);
    cout << "Printing heap: " << endl;
    for(int i = 1; i<=n; i++){
     cout << arr[i] << " ";
    }

    cout << endl;

    heapSort(arr, n);

    cout << "Printing heap: " << endl;
    for(int i = 1; i<=n; i++){
     cout << arr[i] << " ";
    }

    cout << endl;
}