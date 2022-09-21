//------------------------------------
//      Getting the middle of linked list - APPROACH - 2 
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

void print(Node* &head){
     Node* temp = head;
     while(temp != NULL){
          cout << temp -> data << " ";
          temp = temp -> next;
     }
     cout << endl;
}

Node* getMiddle(Node* head){
     if(head == NULL || head -> next == NULL){
          return NULL;
     }

     if(head -> next -> next == NULL){
          return head -> next;
     }

     Node* slow = head;
     Node* fast = head -> next;

     while(fast != NULL){
          fast = fast -> next;
          if(fast != NULL){
               fast = fast -> next;
          }
          slow = slow -> next;
     }
     return slow;

}

int main(){
     Node* node1 = new Node(16);
     Node* head = node1;

     InsertAtHead(head, 14);
     InsertAtHead(head, 12);
     InsertAtHead(head, 10);
     InsertAtHead(head, 8);
     print(head);
     Node* middle = getMiddle(head);
     cout << "The middle of the linked list is: " << middle -> data << endl;
}