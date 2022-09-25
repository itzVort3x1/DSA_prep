//------------------------------------
//      Remove Duplicates from a sorted linked list
//------------------------------------

#include<iostream>
using namespace std;

class Node {
     public:
     int data;
     //here the type is node address
     Node* next;

     //constructor incase of linked list
     Node(int data){
          this -> data = data;
          this -> next = NULL;
     }

     //destructor
     ~Node(){
          int value = this -> data;
          if(this->next != NULL){
               delete next;
               next = NULL;
          }
          cout << " memory is free for node with data " << value << endl;
     }
};

void insertAtHead(Node* &head, int d){
     // new node creation
     Node* temp = new Node(d);
     temp -> next = head;
     head = temp;
}

void removeDuplicated(Node* &head){

     if(head == NULL){
          return;
     }

     Node* temp = head;
     while(temp != NULL){
          if((temp -> next != NULL) && temp -> data == temp -> next -> data){
               temp -> next= temp -> next -> next;
          }else {
               temp = temp -> next;
          }
     }
     return;
}

void print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

int main(){

     //created a new node
     Node* node1 = new Node(4);
     // cout << node1 -> data << endl;
     // cout << node1 -> next << endl;

     // head pointed to node1;
     Node* head = node1;
     Node* tail = node1;
     insertAtHead(head, 3);
     insertAtHead(head, 2);
     insertAtHead(head, 2);
     insertAtHead(head, 1);
     print(head);

     removeDuplicated(head);
     print(head);



     return 0;
}