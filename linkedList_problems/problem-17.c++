//------------------------------------
//      Sort linked list of 0s 1s 2s
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
}

void Print(Node* head){
     Node* temp =  head;

     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

Node* sortList(Node* head){
     Node* zeroHead = new Node(-1);
     Node* zeroTail = zeroHead;
     Node* oneHead = new Node(-1);
     Node* oneTail = oneHead;
     Node* twoHead = new Node(-1);
     Node* twoTail = twoHead;
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

}