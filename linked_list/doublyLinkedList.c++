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

     return 0;
}