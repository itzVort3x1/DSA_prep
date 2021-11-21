// -------------------------
//         1 
//         2 3
//         3 4 5 
//         4 5 6 7 
//         5 6 7 8 9 
// -------------------------

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int row = 1;
    while(row<=n){
        int col = 1;
        int value = row;
        while(col<=row){
            cout<<value<<" ";
            value++;
            col++;
        }
        cout<<endl;
        row++;
    }
}

// how to solve this with out using value variable

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int row = 1;
    while(row<=n){
        int col = 1;
        while(col<=row){
            cout<<row + col - 1<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}