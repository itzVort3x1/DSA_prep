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

void InsertAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp;
};

void print(Node* head){
     while(head != NULL){
          cout << head -> data << " ";
          head = head -> next;
     };
     cout << endl;
}

bool isCircular(Node* head){
     //empty list
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

     Node* node1 = new Node(20);
     Node* head = node1;

     InsertAtHead(head, 18);
     InsertAtHead(head, 16);
     InsertAtHead(head, 14);
     InsertAtHead(head, 12);
     InsertAtHead(head, 10);
     print(head);

     if(isCircular(head)){
          cout << "The given list is circular" << endl;
     }else {
          cout << "The given list is not circular" << endl;
     }

     return 0;

}