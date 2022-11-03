//------------------------------------
//      Copy set bits in a range
//------------------------------------

#include<iostream>
using namespace std;

int main(){
     //input x = 44, y = 3, l = 1, r = 5;
     int x = 44;
     int y = 3;
     int l = 1;
     int r = 5;

     for(int i=l; i<r; i++){
          int mask = 1 << (i-1);

          if(y & mask){
               x = x | mask;
          }

     }

     cout << x << endl;

}