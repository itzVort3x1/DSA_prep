//------------------------------------
//        Clone a linked list with next and random pointer
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
          }
     }
};


int main(){
     
}