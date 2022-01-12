#include<iostream>

using namespace std;

int main(){
    // if the rows and columns are the same.
    /*
    int n;
    cin>>n;

    int** arr = new int*[n];

    // creating a 2D array
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    // taking input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // ouput
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    // if the number of rows and columns are different
    int row;
    cin>>row;

    int col;
    cin>>col;

    int** arr = new int*[row];

    for(int i=0; i<col; i++){
        arr[i] = new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memeory
    for(int i=0; i<col; i++){
        delete [] arr[i];
    }

    delete [] arr;
}