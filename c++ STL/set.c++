#include<iostream>
#include<set>

using namespace std;

int main(){
    // stores only unique elements.
    // it uses bst to store data.
    set<int> s;
    s.insert(5); 
    s.insert(5); 
    s.insert(4); 
    s.insert(4); 
    s.insert(4); 
    s.insert(4); 
    s.insert(2); 
    s.insert(1); 
    s.insert(5);

    // ignores duplicate elements if present.

    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    
    s.erase(s.begin());
    
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"5 is present or not-> "<<s.count(5)<<endl;
    
    set<int>::iterator itr = s.find(5);
    
    cout<<"value present at itr-> "<<*itr<<endl;
}