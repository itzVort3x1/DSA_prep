#include<iostream>
#include<array>

using namespace std;

int main() {
    // basic initialization of array
    int basic[3] = {1,2,3};

    // STL initialization of array
    array<int, 4> a = {1,2,3,4};

    int size = a.size();

    for(int i =0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // other operation on STL ARRAY.
    cout<< "Element at 2nd Index-> "<<a.at(2)<<endl;
    cout<< "Empty or not -> "<<a.empty()<<endl;

    cout<<"First Element-> "<<a.front()<<endl;
    cout<<"Last Element-> "<<a.back()<<endl;
}