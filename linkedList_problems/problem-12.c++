//------------------------------------
//      detect if there is a loop in linked list using floyd's cycle detection algorithm
//------------------------------------

#include<iostream>
#include<map>
using namespace std;

class Node{
     public:
     int data;
     Node* next;

     Node(int d){ 
          this -> data = d;
          this -> next = NULL;
     }

     ~Node(){
          int value = this -> data;
          if(this -> next != NULL){
               delete next;
               next = NULL; 
          }
          cout << "Memory is free for node with data " << value << endl;
     }
};

void insertNode(Node* &tail, int element, int d){
     //assuming that the element is present in the list 

     //empty list
     if(tail == NULL){
          Node* newNode = new Node(d);
          tail = newNode;
          newNode -> next = newNode;
     }else {
          //non-empty list
          //assuming that the element is present in the list
          Node* curr = tail;
          while(curr -> data != element){
               curr = curr -> next;
          }

          //element found -> curr is representing the element
          Node* temp = new Node(d);
          temp -> next = curr -> next;
          curr -> next = temp;
     }
}

void print(Node* tail){
     Node* temp = tail;

     do{
          cout << tail -> data << " ";
          tail = tail -> next;
     }while(tail != temp);
     cout << endl;
}

void deleteNode(Node* &tail, int value){
     //empty list
     if(tail == NULL){
          cout << " List is empty, please check again" << endl;
          return;
     }else {
          //non-empty
          //assuming that "value" is present in the linked list
          Node* prev = tail;
          Node* curr = prev -> next;

          while(curr -> data != value){
               prev = curr;
               curr = curr -> next;
          }

          prev -> next = curr -> next;
          if(tail == curr){
               tail = prev;
          }
          curr -> next = NULL;
          delete curr;

     }
}

bool isCircular(Node* head){
     //empty list
     if(head == NULL){
          return true;
     }

     Node* temp = head -> next;
     while(temp != NULL && temp != head){
          temp = temp -> next;
     }

     if(temp == head){
          return true;
     }

     return false;

}

bool detectLoop(Node* &head){
     if(head == NULL){
          return false;
     }

     map<Node*, bool> visited;

     Node* temp = head;

     while(temp != NULL){
          //cycle detected
          if(visited[temp]){
               return true;
          }

          visited[temp] = true;
          temp = temp -> next;
     }

     return false;

}

bool floydDetectLoop(Node* head){

     if(head == NULL){
          return false;
     }

     Node* slow = head;
     Node* fast = head;

     while(slow != NULL && fast != NULL){
          fast = fast -> next;
          if(fast != NULL){
               fast = fast -> next;
          }
          slow = slow -> next;

          if(slow == fast){
               cout << "cycle present at " << slow -> data << endl;
               return true;
          }
     }

     return false;
}

int main(){
     Node* tail = NULL;

     //inserting in empty list
     insertNode(tail, 5, 3);
     // print(tail);

     insertNode(tail, 3, 4);
     // print(tail);

     insertNode(tail, 4, 6);
     // print(tail);

     insertNode(tail, 6, 7);
     // print(tail);

     // deleteNode(tail, 4);
     // print(tail);

     // if(isCircular(tail)){
     //      cout << "This is a circular linked list." << endl;
     // }else {
     //      cout << "This is not a circular linked list" << endl;
     // }

     if(floydDetectLoop(tail)){
          cout << "Loop exists in this linked list" << endl;
     }else {
          cout << "Loop does not exist in this linked list" << endl;
     }

     return 0;
}