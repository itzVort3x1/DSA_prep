#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
     // creation
     unordered_map<string, int> mapping;

     // insertion
     pair<string, int> p = make_pair("test", 25);
     pair<string, int> q("test1", 24);

     pair<string, int> r;
     r.first = "test3";
     r.second = 21;

     mapping.insert(p);
     mapping.insert(q);
     mapping.insert(r);

     cout << "Size of map: " << mapping.size() << endl;

     cout << mapping.at("test") << endl;
     cout << mapping["test1"] << endl;

     cout << mapping.count("test") << endl;

     if(mapping.find("test3 ") != mapping.end()){
          cout << "Found" << endl;
     } else {
          cout << "Not Found" << endl;
     }

     return 0;
}