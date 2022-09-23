//------------------------------------
//      Linked list reverse K groups
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
     };
};

void InsertAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp;
};

void print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

Node* Kreverse(Node* &head, int k){
     //base case
     if(head == NULL){
          return NULL;
     }
     
     Node* next = NULL;
     Node* curr = head;
     Node* prev = NULL;
     int count = 0;
     while(curr != NULL && count < k){
          next = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = next;
          count++;
     }

     //step2: recursion
     if(next != NULL){
          head -> next = Kreverse(next, k);
     }

     //step3: return value
     return prev;

};

int main(){
     Node* node1 = new Node(20);
     Node* head = node1;

     InsertAtHead(head, 18);
     InsertAtHead(head, 16);
     InsertAtHead(head, 14);
     InsertAtHead(head, 12);
     InsertAtHead(head, 10);
     InsertAtHead(head, 8);
     // Kreverse(head, 2);
     Node* res = Kreverse(head, 2);
     print(res);
}