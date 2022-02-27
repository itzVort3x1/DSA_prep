//------------------------------------
//      detect if the linked list is circular or not.
//------------------------------------

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertNode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }else {
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

bool isCircular(Node* head){

    // empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head -> next;

    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }

    return false;
}

int main(){
    Node* tail = NULL;

    InsertNode(tail, 5, 3);

    InsertNode(tail, 3, 5);
    print(tail);

    if(isCircular(tail)){
        cout<<"The given linked list is circular"<<endl;
    }else {
        cout<<"The given list is not circular"<<endl;
    }

    return 0;

}