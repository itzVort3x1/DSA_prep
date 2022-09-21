//------------------------------------
//      Getting the middle of linked list
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
     
     //create new node
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

int getLength(Node* &head){
     int count = 0;
     Node* temp = head;
     while(temp != NULL){
          count++;
          temp = temp -> next;
     }
     return count;
}

void getMiddle(Node* &head){
     
     int len = getLength(head);
     // cout << "Length of the linked list is: " << len << endl;
     int ans = (len/2);

     Node* temp = head;
     int cnt = 0;
     while(cnt < ans){
          temp = temp -> next;
          cnt++;
     }
     cout << "The middle part of the linked list is: " << temp -> data << endl;

}


int main(){

     Node* node1 = new Node(16);

     Node* head = node1;

     InsertAtHead(head, 14);
     InsertAtHead(head, 12);
     InsertAtHead(head, 10);
     InsertAtHead(head, 8);
     print(head);
     getMiddle(head);

}