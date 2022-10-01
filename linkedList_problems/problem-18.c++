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

Node* merge(Node* &first, Node* &second){

     //if only one element is present in first list
     if(first -> next == NULL){
          first -> next = second;
          return first;
     }

     Node* curr1 = first;
     Node* next1 = first -> next;
     Node* curr2 = second;
     Node* next2 = second -> next;

     while(next1 != NULL && curr2 != NULL){
          if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
               // add node in between the first and second node
               curr1 -> next = curr2;
               next2 = curr2 -> next;
               curr2 -> next = next1;
               //update pointers
               curr1 = curr2;
               curr2 = next2;
          }else {
               // curr1 and next1 move it forward
               curr1 = next1;
               next1 = next1 -> next;
               if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
               }
          }
     }
     return first;
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

     cout << "The First Linked List: ";
     Print(head1);
     cout << "The Second Linked List: "; 
     Print(head2);

     if(head1 == NULL){
          Print(head2);
     }

     if(head2 == NULL){
          Print(head1);
     }
     Node* res;
     if(head1 -> data <= head2 -> data){
          res = merge(head1, head2);
     }else {
          res = merge(head2, head1);
     } 

     cout<< "Merged Linked List: ";
     Print(res);
}