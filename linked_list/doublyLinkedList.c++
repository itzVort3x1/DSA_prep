#include<iostream>
using namespace std;

class Node{
     public:
     Node* prev;
     Node* next;
     int data;


     Node(int d){
          this -> data = d;
          this -> prev = NULL;
          this -> next = NULL;
     }

     ~Node(){
          int val = this -> data;
          if(next != NULL){
               delete next;
               next = NULL;
          }

          cout << "Memory free for node with data " << val << endl;
     }

};

void print(Node* head){
     Node* temp = head;

     while(temp != NULL){
          cout << temp -> data <<  " ";
          temp = temp -> next;
     }

     cout << endl;
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

void insertAtHead(Node* &head, Node* &tail, int d){

     // empty list
     if(head == NULL){
          Node* temp = new Node(d);
          head = temp;
          tail = temp;
     }else {
          Node* temp = new Node(d);
          temp -> next = head;
          head -> prev = temp;
          head = temp;
     }
}

void insertAtTail(Node* &head, Node* &tail, int d){

     if(head == NULL){
          Node* temp = new Node(d);
          tail = temp;
          head = temp; 
     }else {
          Node* temp = new Node(d);

          tail -> next = temp;
          temp -> prev = tail;
          tail = temp;
     }
}

void insertAtPosition(Node* &head, Node* &tail,int position, int d){
     if(position == 1){
          insertAtHead(head, tail, d);
          return;
     }

     Node* temp = head;
     int cnt = 1;

     while(cnt < position -1){
          temp = temp -> next;
          cnt++;
     }

     if(temp -> next == NULL){
          insertAtTail(head, tail, d);
          return;
     }

     Node* nodeToInsert = new Node(d);
     nodeToInsert -> next = temp -> next;
     temp -> next -> prev = nodeToInsert;
     temp -> next = nodeToInsert;
     nodeToInsert -> prev = temp;

}

void deleteNode(int d, Node* &head){
     if(d == head -> data){
          Node* temp = head;
          temp -> next -> prev = NULL;
          head = temp -> next;
          temp -> next = NULL;
          //memory free start node
          delete temp;
     }else {
          // deleting any middle node or last node
          Node* curr = head;
          Node* prev = NULL;

          while(d == curr -> data){
               prev = curr;
               curr = curr -> next;
          }

          curr -> prev = NULL;
          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;
     }
}

int main(){
     Node* node1 = new Node(10);
     Node* head = node1;
     Node* tail = node1;

     print(head);

     cout << "length of the linked list: " << getLength(head) << endl;

     insertAtHead(head, tail, 11);
     print(head);
     insertAtHead(head, tail,  13);
     print(head);
     insertAtHead(head, tail,  18);
     print(head);
     insertAtTail(head, tail, 25);
     print(head);
     insertAtPosition(head, tail, 2, 100);
     print(head);
     insertAtPosition(head, tail, 1, 101);
     print(head);
     insertAtPosition(head, tail, 8, 102);
     print(head);
     deleteNode(1, head);
     print(head);

     return 0;
}