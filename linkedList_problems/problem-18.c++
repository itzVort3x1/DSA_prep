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

int main(){
     Node* node1 = new Node(15);
     Node* head = node1;
}