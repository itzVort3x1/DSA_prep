//------------------------------------
//      Bit Difference
//------------------------------------

#include<iostream>
using namespace std;


int main(){

     int n;

     int a, b;
     cout << "Enter the two number you want to find the bit difference for: ";
     cin >> a;
     cin >> b;

     n = a ^ b;

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
