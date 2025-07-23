#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid){

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;
    for(int i = 0; i<len1; i++){
        first[i] = arr[k++];
    }

    k = mid + 1;
    for(int i = 0; i<len2; i++){
        second[i] = arr[k++];
    }

    int index1 = 0;
    int index2=0;
    k = start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++]; 
        }else {
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[k++] = first[index1++];
    }

    while(index2 < len2){
        arr[k++] = second[index2++];
    }

}

void mergeSort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, end, mid);
    }
}

int main() {
    vector<int> arr = {38,27,43,3,9,82,10};

    int start = 0;
    int end = arr.size() - 1;

    mergeSort(arr, start, end);

    cout << "Sorted Array: " << endl;
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}