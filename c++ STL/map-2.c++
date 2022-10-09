#include<iostream>
#include<map>
using namespace std;

int main(){
     map<string, int> marksMap;
     marksMap["Harry"] = 98;
     marksMap["Jack"] = 59;
     marksMap["Rohan"] = 45;

     map<string, int> :: iterator itr;

     for(itr=marksMap.begin(); itr != marksMap.end(); itr++){
          cout << (*itr).first << " " << (*itr).second << "\n";
     }

     return 0;
}