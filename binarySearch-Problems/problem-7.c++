//------------------------------------
//      Square root of a number using binary search upto a decimal point.
//      Ex: INPUT: N = 37
//          OUTPUT: 6.082
//          EXPLANATION: Square root of 37 is 6.082 upto 3 decimal places.
//------------------------------------

#include<iostream>
using namespace std;

int sqrtInteger(int n){
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

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i<precision;i++){
        factor = factor / 10;
        for(double j = ans; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number you want to find the square root for: ";
    cin>>n;

    int tempSol = sqrtInteger(n);
    cout<<"Square root of the number is: "<<morePrecision(n,3, tempSol)<<endl;

    return 0;
}