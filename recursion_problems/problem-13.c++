//------------------------------------
//      Tower of Hanoi
//              INPUT: N = 3
//              OUTPUT: move disk 1 from rod 1 to rod 3
//                      move disk 1 from rod 3 to rod 2
//                      move disk 2 from rod 1 to rod 2
//                      move disk 3 from rod 1 to rod 3
//                      move disk 1 from rod 2 to rod 1
//                      move disk 2 from rod 2 to rod 3
//                      move disk 1 from rod 1 to rod 3
//                      7
//              EXPLANATION: For N=3 , steps will be
//                          as follows in the example and total
//                          7 steps will be taken
//------------------------------------

#include<iostream>

using namespace std;

void toh(int n, int from , int to, int aux){
    if(n >= 1){
        toh(n-1, from, aux, to);
        cout<<"move disk "<<n<<" from "<< from << " to "<< to << endl;
        toh(n-1, aux, to, from);
    }
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int from = 1;
    int to = 3;
    int aux = 2;

    toh(n, from, to, aux);


}