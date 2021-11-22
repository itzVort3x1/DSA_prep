// -------------------------
//                  1   
//                2 2 
//              3 3 3
//            4 4 4 4
// -------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int space = n-i+1;
        while(space){
            cout<<" ";
            space-=1;
        }

        int j=1;
        while(j<=i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}