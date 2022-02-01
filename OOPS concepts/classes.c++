#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    //properties of the class
    private:
    int health;

    public:
    char *name;
    char level;

    // default copy makes a shallow copy
    Hero(){
        cout<<"Constuctor called"<<endl;
        name = new char[100];
    }

    //Parameterised constructor
    Hero(int health){
        this->health = health;
    }

    //copy constructor
    Hero(Hero& temp){
        cout<<"Copy constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout<<endl;
        cout<<"level is: "<<level<<endl;
        cout<<"health is: "<<health<<endl;
        cout<<"name: "<<name<<endl;
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

    void setName(char name[]){
        strcpy(this->name, name);
    }

};

int main(){

    //static allocation
    Hero h1;
    h1.setHealth(12);
    h1.setLevel('D');
    char name[7] = "hellos";
    h1.setName(name);

    h1.print();

    // copying hero h1 object
    Hero h3(h1);

    
    // cout<<"level: "<<h1.getLevel()<<endl;
    // cout<<"health: "<<h1.getHealth()<<endl;

    //dyncamic allocation
    Hero *h2 = new Hero(10);
    // h2->setLevel('S');
    // h2->setHealth(200);
    // cout<<"level h2: "<<(*h2).getLevel()<<endl;
    cout<<"health h2: "<<(*h2).getHealth()<<endl;
    // cout<<"health h2: "<<h2->level<<endl;

    // cout<<"size: "<<sizeof(h1)<<endl;
    // cout<<"Hero's health is: "<< h1.getHealth() <<endl;

    // h1.setHealth(70);
    // h1.setLevel('A');

    // cout<<"size: "<<sizeof(h1)<<endl;
    // cout<<"health: "<<h1.getHealth()<<endl;
    // cout<<"level: "<<h1.getLevel()<<endl;
    // h1.print();

    return 0;
}