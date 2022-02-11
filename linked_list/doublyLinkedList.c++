#include<iostream>

using  namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this-> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head,int position, int data, Node* &tail){
    // insert at start case
    if(position == 1){
        InsertAtHead(head, data);
    }


    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp-> next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail, data);
    }

    //create a new node
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    // cout<<"Length of linked list: "<<getLength(head)<<endl;

    InsertAtTail(tail, 11);
    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtHead(head, 8);
    print(head);

    InsertAtPosition(head, 3, 5, tail);
    print(head);


    return 0;
}