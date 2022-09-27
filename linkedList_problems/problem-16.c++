//------------------------------------
//      Remove Duplicates from a unsorted linked list
//------------------------------------

#include<iostream>
#include<map>
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

void print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}


void removeDuplicates(Node* &head){
     if(head == NULL){
          return;
     }

     Node* temp = head;
     while(temp != NULL){
          Node* curr = temp -> next;
          Node* prev = temp;
          print(head);
          while(curr != NULL){
               if(temp -> data == curr -> data){
                    prev -> next = curr -> next -> next;
                    curr = curr -> next;
               }else {
                    prev = curr;
                    curr = curr -> next;
               }
          }
          temp = temp -> next;
     }     
}

// void removeDuplicatedUsingMap(Node* &head){
//      if(head == NULL){
//           return;
//      }

//      map<Node*, bool> visited;

//      Node* temp = head;
//      Node* prev = head;

//      while(temp != NULL){
          
//           if(visited[temp]){
//                prev -> next = curr -> next -> next;
//                curr = curr -> next;
//           }else {
//                visited[temp] = true;
//                prev = curr;
//                curr = curr -> next;
//           }
//      }
//      // return head;
// }


int main(){

     //created a new node
     Node* node1 = new Node(2);
     // cout << node1 -> data << endl;
     // cout << node1 -> next << endl;

     // head pointed to node1;
     Node* head = node1;
     Node* tail = node1;
     insertAtHead(head, 1);
     insertAtHead(head, 1);
     insertAtHead(head, 4);
     insertAtHead(head, 2);
     insertAtHead(head, 1);
     insertAtHead(head, 3);
     insertAtHead(head, 1);
     print(head);

     removeDuplicates(head);
     print(head);

     return 0;
}