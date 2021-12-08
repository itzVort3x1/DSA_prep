//------------------------------------
//      Square root of a number using binary search
//      Ex: INPUT: N = 25
//          OUTPUT: 5
//          EXPLANATION: Square root of 25 is 5.
//------------------------------------

#include<iostream>
using namespace std;

int binarySearch(int n){
    int s = 0;
    int e = n;

    long long int mid = s + (e-s)/2;

    long long int ans = -1;

    while(s<=e){
        long long int square = mid*mid;

        if(square == n){
            return mid;
        }
        if(square < n){
            ans = mid;
            s = mid + 1;
        }else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number you want to find the square root for: ";
    cin>>n;

    cout<<"Square root of the number is: "<<binarySearch(n)<<endl;

    return 0;
}