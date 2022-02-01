#include<iostream>

using namespace std;

class Hero{
    public:
        int health;
        char level;

        void print(){
            cout<<endl;
            cout<<"level is: "<<level<<endl;
            cout<<"health is: "<<health<<endl;
        }

        int getHealth(){
            return health;
        }

        char getLevel(){
            return level;
        }

        void setHealth(int h){
            health = h;
        }

        void setLevel(char ch){
            level = ch;
        }

};

int main(){
    Hero h1;
    h1.setHealth(12);
    h1.setLevel('D');
    h1.print();

    Hero h2;
    h2 = h1;
    h2.print();

}