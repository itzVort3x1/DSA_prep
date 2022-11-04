//------------------------------------
//      Minimize the Heights
//------------------------------------

#include<iostream>
using namespace std;

int main(){

     int k;
     cout << "Enter size k: ";
     cin >> k;

     int n;
     cout << "Enter the size of array: ";
     cin >> n;

     int arr[] = {1, 5, 8, 10};

     sort(arr, arr+n);
     int max_ = arr[n-1];
     int min_ = arr[0];
     int res = max_ - min_;

     for(int i=1; i < n; i++){
          max_ = max(arr[i-1]+k, arr[n-1]-k);
          min_ = min(arr[i]-k, arr[0]+k);

          res = min(res, max_ - min_);
     }
     
     cout << res << endl;
     return 0;
};