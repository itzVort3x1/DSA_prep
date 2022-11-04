//------------------------------------
//      Count Total Set Bits
//------------------------------------

#include<iostream>
using namespace std;

int main(){
     int count = 1;
     for(int i=0; i<=4; i++){
          int k = i;
          while(k != 1){
               int digit = k%2;
               if(digit == 1){
                    count++;
               }
               k = k/2;
          }
     }

     cout << count << endl;
}