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

void insertAtTail(Node* &tail, int d){
     // new node creation
     Node* temp = new Node(d);
     tail -> next = temp;
     tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

     //insert at start
     if(position == 1){
          insertAtHead(head, d);
          return;
     }

     Node* temp = head;
     int cnt = 1;
     while(cnt < position - 1){
          temp = temp -> next;
          cnt++;
     }

     if(temp -> next == NULL){
          insertAtTail(tail,d);
          return;
     }

     // createing a node for d
     Node* nodeToInsert = new Node(d);
     nodeToInsert -> next = temp -> next;
     temp -> next = nodeToInsert;

}

void deleteNodeByPosition(int position, Node* &head){

     // deleting start node
     if(position == 1){
          Node* temp = head;
          head = head -> next;
          temp -> next = NULL;
          //memory free start node
          delete temp;
     }else {   
          //deleting any middle node or last node
          Node* curr = head;
          Node* prev = NULL;

          int cnt = 1;
          while(cnt < position){
               prev = curr;
               curr = curr -> next;
               cnt++;
          }
          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;
     }
}

void deleteNodeByValue(int d, Node* &head){
     if(d == head -> data){
          Node* temp = head;
          head = head -> next;
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

          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;
     }
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
     Node* node1 = new Node(5);
     // cout << node1 -> data << endl;
     // cout << node1 -> next << endl;

     // head pointed to node1;
     Node* head = node1;
     Node* tail = node1;
     print(head);

     insertAtTail(tail, 12);

     print(head);

     insertAtTail(tail, 15);

     print(head);

     insertAtPosition(head, tail,3, 22);

     print(head);

     cout << "head: " << head -> data << endl;
     cout << "tail: " << tail -> data << endl;

     deleteNodeByPosition(3, head);

     print(head);

     deleteNodeByValue(5, head);

     print(head);


     return 0;
}