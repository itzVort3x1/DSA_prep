#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<" memory is free for node with data " << value << endl;
    }
};

void InsertNode(Node* &tail, int element, int d){
    //assuming that the element is present in the list

    
}

int main(){

    Node* node1 = new Node(10);

    Node* tail = node1;
    
}