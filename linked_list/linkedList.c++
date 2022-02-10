#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        //memeory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<" memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node* &head ,int d){

    //create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){

    //create new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertAtPosition(int position, int d, Node* &head, Node* &tail){

    // insert at start case
    if(position == 1){
        InsertAtHead(head, d);
    }


    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp-> next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail, d);
    }

    //create a new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;

}

void deleteNode(int position, Node* &head, Node* &tail){

    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //memory free start node
        temp->next = NULL;
        delete temp;

    }else {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr -> next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node * node1 = new Node(10);
    // cout<<node1 -> data <<endl;
    // cout<<node1 -> next <<endl;
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtHead(head, 8);
    print(head);

    InsertAtPosition(3, 11, head, tail);
    print(head);

    cout<<"head: "<<head -> data <<endl;
    cout<<"tail: "<<tail -> data <<endl;

    deleteNode(5, head, tail);
    print(head);

    cout<<"head: "<<head -> data <<endl;
    cout<<"tail: "<<tail -> data <<endl;



    return 0;
}