#include<iostream>

using namespace std;

class Hero{
    public:
        int health;
        char level;
        static int timeToComplete;

        void print(){
            cout<<endl;
            cout<<"level is: "<<level<<endl;
            cout<<"health is: "<<health<<endl;
        }

        static int random(){
            return timeToComplete;
        }
};

int Hero::timeToComplete = 5;

int main(){
    //static functions can access only static variables.
    cout<<Hero::timeToComplete<<endl;
    cout<<Hero::random()<<endl;

    Hero a;
    cout<<a.timeToComplete<<endl;

    // do not access static variable like this
    Hero b;
    b.timeToComplete = 10;
    cout<<a.timeToComplete<<endl;
    cout<<b.timeToComplete<<endl;

}