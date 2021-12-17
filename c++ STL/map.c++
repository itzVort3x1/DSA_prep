#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, int> m;
    
    m[1] = 123;
    m[2] = 234;
    m[13] = 345;
    
    m.insert({5, 456});
    
    
    for(auto i:m){
        cout<<i.first<<" "<< i.second<<endl;
    }
    
    // finds for key 13;
    cout<<"finding 13-> "<<m.count(13)<<endl;
    
    m.erase(13);
    
    for(auto i:m){
        cout<<i.first<<" "<< i.second<<endl;
    }

    auto it = m.find(5);

    for(auto i=it; i!=m.end(); i++){
        cout<<(*i).first<<endl;
    }
}