// -------------------------
//           1 2 3 4   
//             2 3 4 
//               3 4
//                 4
// -------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        int space = i-1;
        while(space){
            cout<<" ";
            space-=1;
        }

        int j=i;
        while(j<=n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}