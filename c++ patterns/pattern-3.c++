// -------------------------
//         1 2 3 4 5
//         1 2 3 4
//         1 2 3
//         1 2
//         1
// -------------------------

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 1;
    while(i<=n){
        int j=0;
        while(j<=n){
            cout<<j;
            j-=i;
        }
    }
    i++;
}