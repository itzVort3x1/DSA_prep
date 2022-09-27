//------------------------------------
//        Check if the linked list is palindrome or not
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

void InserAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp -> next = head;
     head = temp; 
}

void Print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

int main(){
     Node* node1 = new Node(5);
     Node* head = node1;

     InserAtHead(head, 4);
     InserAtHead(head, 3);
     InserAtHead(head, 4);
     InserAtHead(head, 5);

     Print(head);
}