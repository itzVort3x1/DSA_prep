#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    int flag = 0;
    for(int i =0; i<size; i++ ){
        if(arr[i] == key){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    int arr[10] = {5,7,-2,10,22,-2,0,5,22,1};

    cout<<"Enter the element to search for: ";
    int key;
    cin>>key;

    bool found = search(arr, 10, key);

    if( found ){
        cout<<"Key is Present"<<endl;
    }else {
        cout<<"Key not found"<<endl;
    }
}