#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
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



    return 0;
}