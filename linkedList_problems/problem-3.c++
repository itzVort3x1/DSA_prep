//------------------------------------
//      Linked list reverse K groups
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

void InsertAtHead(Node* &head ,int d){

    //create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};

Node* kReverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while( curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step2: recursion
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    return prev;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;

    InsertAtHead(head, 12);
    // print(head);

    InsertAtHead(head, 14);
    // print(head);

    InsertAtHead(head, 16);
    print(head);

    InsertAtHead(head, 18);
    print(head);

    Node* res = kReverse(head, 2);
    print(res);
};