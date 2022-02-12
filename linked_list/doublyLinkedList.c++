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

void InsertAtHead(Node* &tail ,Node* &head, int data){

    //
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;

    }else {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

void InsertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
    }else {
        Node* temp = new Node(data);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head,int position, int data, Node* &tail){
    // insert at start case
    if(position == 1){
        InsertAtHead(tail,head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp-> next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail, head,data);
        return;
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

    InsertAtTail(tail, head,11);
    print(head);

    InsertAtTail(tail, head,12);
    print(head);

    InsertAtHead(head, head,8);
    print(head);

    InsertAtPosition(head, 3, 100, tail);
    print(head);

    InsertAtPosition(head, 1, 101, tail);
    print(head);

    cout<< "head "<<head -> data<<endl;
    cout<< "tail "<<tail -> data<<endl;


    return 0;
}