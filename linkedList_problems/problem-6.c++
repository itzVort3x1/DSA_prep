//------------------------------------
//      Reversing a linked list using recursion.
//------------------------------------

#include<iostream>
using namespace std;

class Node{
     public:
     Node* next;
     int data;

     Node(int data){
          this -> data = data;
          this -> next = NULL;
     }
};

void InsertAtHead(Node* &head, int data){
     
     //create new node
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp;
};

void print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp ->data << " ";
          temp = temp -> next;
     };
     cout << endl;
};

void reverseLinkedList(Node* &head, Node* curr, Node* prev){

     if(curr == NULL){
          head = prev;
          return;
     }

     Node* forward = curr -> next;
     reverseLinkedList(head, forward, curr);
     curr -> next = prev;
     
}

int main(){
     Node* node1 = new Node(10);

     Node* head = node1;

     InsertAtHead(head, 12);
    // print(head);

    InsertAtHead(head, 14);
    // print(head);

    InsertAtHead(head, 16);
    cout<<"Before reversing the linked list: "<<endl;
    print(head);

    Node* prev = NULL;
    Node* curr = head;
    reverseLinkedList(head, curr, prev); 

    cout << "After reversing the linked list: "<<endl;
    print(head);
}