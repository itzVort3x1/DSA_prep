//------------------------------------
//      Reversing a linked list 
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

void reverseLinkedList(Node* &head){

     if(head == NULL || head -> next == NULL){
          cout << "There is only one element cannot reverse the list"<< endl;
     }

     Node* prev = NULL;
     Node* curr = head;
     Node* forward = NULL;

     while(curr != NULL){
          forward = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = forward;
     }
     head = prev;
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

    reverseLinkedList(head);
    cout << "After reversing the linked list: "<<endl;
    print(head);
}