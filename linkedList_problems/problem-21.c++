//------------------------------------
//        Add 2 Numbers represented by Linked Lists
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

class Node{
     public:
     int data;
     Node* next;

     Node(int data){
          this -> data = data;
          this -> next = NULL;
     };

     ~Node(){
          if(this -> next != NULL){
               delete next;
               next = NULL;
          }
     }
};

void InsertAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp;
}

void Print(Node* head){
     while(head != NULL){
          cout << head -> data << " ";
          head = head -> next;
     }
     cout << endl;
}

Node* reverseList(Node* head){
     Node* curr = head;
     Node* prev = NULL;
     Node* next = NULL;

     while(curr != NULL){
          next = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = next;
     }
     return prev;

}

void InsertAtTail(Node* &head, Node* &tail, int value){
     Node* temp = new Node(value);
     if(head == NULL){
          head = temp;
          tail = temp;
          return;
     }else {
          tail -> next = temp;
          tail = temp;
     }
}

Node* add(Node* first, Node* second){
     int carry = 0;

     Node* ansHead = NULL;
     Node* ansTail = NULL;

     while(first != NULL && second != NULL){
          int sum = carry + first -> data + second -> data;

          int digit = sum % 10;

          // create node and add it in the answer list
          InsertAtTail(ansHead, ansTail, digit);

          carry = sum / 10;
     }
     
}

int main(){
     Node* node1 = new Node(5);
     Node* first = node1;
     InsertAtHead(first, 4);
     InsertAtHead(first, 3);
     cout << "First linked list: ";
     Print(first);

     Node* node2 = new Node(5);
     Node* second = node2;
     InsertAtHead(second, 4);
     cout << "Second linked list: ";
     Print(second);

     first = reverseList(first);
     second = reverseList(second);

     cout << "Reversed first list: ";
     Print(first);

     cout << "Reversed second list: ";
     Print(second);

     Node* ans = add(first, second);
}
