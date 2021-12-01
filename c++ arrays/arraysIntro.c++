#include<iostream>
using namespace std;

//HOLD
void printArray() {

}

int main(){
    //declare
    int number[15];

    //initialising an array

    int second[3] = {5,7,11};

    int third[15] = {2,7};
    int n=15;

    for(int i=0; i<n; i++){
        cout<<third[i]<<endl;
    }

    cout << "Value at 0 index: " << third[1] <<endl;

    return 0;
}