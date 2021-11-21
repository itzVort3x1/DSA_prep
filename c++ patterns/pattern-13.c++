// -------------------------
//         A A A  
//         B B B 
//         C C C 
//         D D D  
//         E E E
// -------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A' + i - 1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}