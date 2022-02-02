#include<iostream>

using namespace std;

class Animal {
    public:
        int age;
        int weight;

    public:
        void bark(){
            cout<<"barking"<<endl;
        }
};

class Human{
    public:
        string color;

    public: 
    void speack(){
        cout<<"speaking"<<endl;
    }
        
};

class Hybrid: public Animal, public Human{

};

int main(){
    Hybrid obj1;
    obj1.speack();
    obj1.bark();

    return 0;
}