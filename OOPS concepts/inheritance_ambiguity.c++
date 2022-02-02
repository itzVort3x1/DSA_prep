#include<iostream>

using namespace std;

class A{
    public:
        void func1(){
            cout<<"I am A"<<endl;
        }
};

class B {
    public:
    void func1(){
        cout<<"I am B"<<endl;
    }
};

class C: public A, public B{


};

int main(){

    C object3;
    object3.A::func1();
    object3.B::func1();

    return 0;
}