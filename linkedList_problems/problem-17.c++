//------------------------------------
//      Sort linked list of 0s 1s 2s
//------------------------------------

#include<iostream>
using namespace std;

class Node{
     public:
     int data;
     Node* next;

     //constructor
     Node(int data){
          this -> data = data;
          this -> next = NULL;
     }

     //destructor
     ~Node(){
          int value = this -> data;
          if(this -> next != NULL){
               delete next;
               next = NULL; 
          }
          cout << "Memory is free for node with data " << value << endl;
     }
};

void InsertAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp;
}

void Print(Node* head){
     Node* temp =  head;

     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

void InsertAtTail(Node* &tail, Node* &curr){
     tail -> next = curr;
     tail = curr;
}


Node* sortList(Node* head){
     Node* zeroHead = new Node(-1);
     Node* zeroTail = zeroHead;
     Node* oneHead = new Node(-1);
     Node* oneTail = oneHead;
     Node* twoHead = new Node(-1);
     Node* twoTail = twoHead;

     Node* curr = head;

     while(curr != NULL){
          int value = curr -> data;

          if(value == 0){
               InsertAtTail(zeroTail, curr);
          }else if(value == 1){
               InsertAtTail(oneTail, curr);
          }else {
               InsertAtTail(twoTail, curr);
          }

          curr = curr -> next;
     }

     //merge the lists

     if(oneHead -> next != NULL){
          zeroTail -> next = oneHead -> next;
     }else {
          zeroTail -> next = twoHead -> next; 
     }

     oneTail -> next = twoHead -> next;
     twoTail -> next = NULL;

     //setup head
     head = zeroHead -> next;

     //delete dummy nodes;
     // delete zeroHead;
     // delete oneHead;
     // delete twoHead;

     return head;


}

int main(){
     Node* node1 = new Node(0);

     Node* head = node1;

     InsertAtHead(head, 1);
     InsertAtHead(head, 1);
     InsertAtHead(head, 0);
     InsertAtHead(head, 2);
     InsertAtHead(head, 0);

     Print(head);

     Node* sortedArray = sortList(head);
     cout << "Sorted linked list is" << endl;
     Print(sortedArray);

}