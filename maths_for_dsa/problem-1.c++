// -------------------------
//      PROBLEM_LINK: https://leetcode.com/problems/count-primes/
//      Sieve of Eratosthenes
//      It is a method of calculating the prime numbers in a given range.
// -------------------------

#include<iostream>
#include<vector>

using namespace std;

int main(){

    int target;

    cout<<"Enter the number to find primes numbers: ";
    cin>>target;

    vector<bool> prime(target+1, true);

    prime[0] = prime[1] = false;
    int count;

    for(int i=2; i<target; i++){
        if(prime[i]){
            count++;
            for(int j=2*i; j<target; j = j+i){
                prime[j]=0;
            }
        }
    }

    cout<<"The number of primes present are: "<<count<<endl;

    return 0;

}