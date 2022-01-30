//------------------------------------
//      PROBLEM LINK: https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1/?track=DSASP-Recursion&batchId=154
//      Lucky number
//              INPUT: N = 5
//              OUTPUT: 0
//------------------------------------

#include<iostream>

using namespace std;
int check(int n, int counter){
    if(counter<=n){
        if(n%counter == 0){
            return false;
        }
        n=n - n/counter;
        return check(n, counter+1);
    }else {
        return true;
    }
}

int main(){
    int n;
    cout<<"Enter a number to check: ";
    cin>>n;

    if(check(n,2)){
        cout<<"The number is a lucky number."<<endl;
    }else {
        cout<<"The given number is not a lucky number."<<endl;
    }

    return 0;
}