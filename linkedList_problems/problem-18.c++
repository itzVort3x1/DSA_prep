//------------------------------------
//        Merge Two Sorted Linked lists
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

     ~Node(){
          if(this -> next != NULL){
               delete next;
               next = NULL;
          }
     }
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
     Node* node1 = new Node(15);
     Node* head1 = node1;
     Node* node2 = new Node(17);
     Node* head2 = node2;

     InserAtHead(head1, 13);
     InserAtHead(head1, 11);
     InserAtHead(head1, 5);
     InserAtHead(head1, 4);


     InserAtHead(head2, 14);
     InserAtHead(head2, 8);
     InserAtHead(head2, 3);
     InserAtHead(head2, 1);

     cout << "The First Linked List" << endl;
     Print(head1);
     cout << "The Second Linked List" << endl; 
     Print(head2);


}