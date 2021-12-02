#include<iostream>
using namespace std;

//HOLD
void printArray(int  arr[], int size) {
    cout<<"printing the array"<<endl;

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Printing DONE"<<endl;
}

int main(){
    //declare
    int number[15] = {5,7,11};

    //initialising an array
    printArray(number, 15);

    char ch[5] = {'a', 'b', 'c', 'd'};

    return 0;
}