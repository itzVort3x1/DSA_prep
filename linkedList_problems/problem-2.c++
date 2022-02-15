//------------------------------------
//      Getting the middle of linked list
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
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void getMiddle(Node* &head){

    if(head == NULL || head -> next == NULL){
        cout<< head -> data << endl;
    }

    if(head -> next -> next == NULL){
        cout<<head -> next -> data << endl;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    cout <<"This is the middle of the linked list: "<<slow -> data << endl;
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

    getMiddle(head);
    // print(head);

    return 0;
}