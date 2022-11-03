//------------------------------------
//      Number of 1 Bits
//------------------------------------

#include<iostream>
using namespace std;

int main(){
     int n;
     cout << "Enter a number to find digits: ";
     cin >> n;

     int count = 1;
     while(n != 1){
          int digit = n%2;
          if(digit == 1){
               count++;
          }
          n = n/2;
     }
     cout << "The number of 1's are: " << count << endl;

     return 0;
}