#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

     //creation
     unordered_map<string, int> m;

     //insertion
     //1
     pair<string, int> p = make_pair("babbar", 3);
     m.insert(p);

     //2
     pair<string, int> q("love", 2);
     m.insert(q);

     //3
     m["mera"] = 1;

     return 0;

}