// -------------------------
//      Greatest common divisor(GCD)
// -------------------------

#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }

    if(b==0){
        return a;
    }

    while(a != b){
        if(a>b){
            a = a-b;
        }else {
            b = b-a;
        }
    }

    return a;
}

int main(){
    int a,b;
    cout<<"Enter two numbers a & b to find gcd: ";
    cin>>a>>b;

    int ans = gcd(a,b);

    cout<<"The gcd of numbers a -> b = "<<ans<<endl;

    return 0;
}