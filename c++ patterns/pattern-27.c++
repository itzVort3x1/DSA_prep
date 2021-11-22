// -------------------------
//     1 2 3 4 5 5 4 3 2 1
//     1 2 3 4 * * 4 3 2 1 
//     1 2 3 * * * * 3 2 1 
//     1 2 * * * * * * 2 1
//     1 * * * * * * * * 1
// -------------------------


#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<j;
            j++;
        }

        int star=(i*2)-2;
        while(star>0){
            cout<<"*";
            star-=1;
        }

        int k = n-i+1;
        while(k>0){
            cout<<k;
            k-=1;
        }

        cout<<endl;
        i++;
    } 
}