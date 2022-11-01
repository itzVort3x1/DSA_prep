//------------------------------------
//      Division without using multiplication, division and mod operator
//------------------------------------

#include<iostream>
using namespace std;

long long solve(long long dividend, long long divisor){

     // set the sign
     int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 0;

     dividend = abs(dividend);
     divisor = abs(divisor);

     long long quotient = 0, temp = 0;

     for(int i=31; i>=0; --i){
          if(temp + (divisor << i) <= dividend){
               temp += divisor << i;
               quotient = quotient | 1 << i;
          }
     }

     if(sign == -1){
          quotient = -quotient;
     }

     return quotient;

}

int main(){

     long long dividend = 43;
     long long divisor = -8;

     long long ans = solve(dividend, divisor);

     cout << ans << endl;

}