#include<iostream>

using namespace std;

int main(){
    int num = 5;

    cout << num << endl;

    int *p = &num;

    // address operator

    cout<<"address of num is ->" <<&num << endl;

    cout<<"Value is -> "<< *p<<endl;
    cout<<"Pointer to int -> "<< p<<endl;

    double d = 4.3;
    double *p2 = &d;

    cout<<"Value is -> "<< *p2<<endl;
    cout<<"Pointer to int -> "<< p2 <<endl;

    cout<<"size of integer is "<< sizeof(num) << endl;
    cout<<"size of pointer is "<< sizeof(p) << endl;

    cout<<"size of integer is "<< sizeof(d) << endl;
    cout<<"size of pointer is "<< sizeof(p2) << endl;

    int i = 5;
    int *p3 = &i;
    cout<<p3<<endl;
    cout<<*p3<<endl;

    cout<<(*p3)++<<endl;
    cout<<*p3<<endl;
    
    //copying a pointer
    int *q = p3;
    cout<< p3 << " - "<< q << endl; 
    cout<< *p3 << " - "<< *q << endl; 

    // pointer arithmetic
    int z = 3;
    int *t = &z;
    cout<<*t <<endl;
    cout<< " before t" << t << endl;
    t = t+1;
    cout<<" after t"<<t<<endl;

    return 0;
}