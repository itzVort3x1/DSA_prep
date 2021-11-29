#include<iostream>
using namespace std;

//1->Even
//0->Odd

bool isEven(int a){
    //odd
    if(a&1){
        return 0;
    }
    //even
    return 1;
}

int main() {
    int num;
    cin>>num;

    if(isEven(num)){
        cout<<"Number is Even";
    }else {
        cout<<"Number is Odd";
    }

    return 0;
}