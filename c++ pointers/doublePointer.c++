#include<iostream>

using namespace std;

void updated(int **p){
    // NO Change
    // p = p + 1;

    // There is a change this case.
    // *p = *p + 1;

    // There is a change in this case.
    // **p = **p + 1;
}

int main(){
    int i=5;
    int* p = &i;
    int** p2 = &p;

    /*
    cout<< "printing p -> "<<p<<endl;
    cout<< "address of p -> "<<&p<<endl;
    cout<< "printing of p2 -> "<<*p2<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;
    */

   cout<<"before "<< i << endl;
   cout<<"before "<< p << endl;
   cout<<"before "<< p2 << endl;
   updated(p2);
   cout<<"after "<< i << endl;
   cout<<"after "<< p << endl;
   cout<<"after "<< p2 << endl;

    return 0;
}