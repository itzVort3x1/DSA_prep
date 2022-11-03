//------------------------------------
//      Find position of the only set bit
//------------------------------------

#include<iostrem>
using namespace std;

int isPowerOfTwo(int n){
     return N && (!(N & (N-1)));
}

int main(){

     int n;
     cout << "Enter a Decimal Number to find set bit: ";
     cin >> n;

     if(!isPowerOfTwo(n)){
          return -1;
     }

     int i=1, pos = 1;

     while(!(i&n)){
          i = i << 1;
          ++pos;
     }

     cout << "The set bit is in position: " << pos << endl;

     return 0;

}