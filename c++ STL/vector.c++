#include<iostream>
#include<vector>

using namespace std;

int main(){
    // Initialization of Vector
    vector<int> v;

    // initialize with a default (size, value);
    vector<int> a(5,1);
    for(int i:a){
        cout<<i<<" ";
    }

    // copying the array 'a' into a new new array
    vector<int> last(a);
    for(int i:a){
        cout<<i<<" ";
    }
    
    cout<<"Size-> "<<v.size()<<endl;
    cout<<"Capacity-> "<<v.capacity()<<endl;

    //to insert element into the vector
    v.push_back(1);
    v.push_back(2);

    cout<<"Element at 2nd Index"<<v.at(0)<<endl;

    cout<<"First Element-> "<<v.front()<<endl;
    cout<<"Last Element-> "<<v.back()<<endl;

    // pops the last element in the array
    v.pop_back();

    // empty the array or clear the array
    v.clear();
}