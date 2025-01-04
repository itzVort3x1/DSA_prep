//------------------------------------
//      Reverse a linked list
//      Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//------------------------------------

#include <iostream>
using namespace std;

class Node {
     public:
     int data;
     //here the type is node address
     Node* next;

     //constructor incase of linked list
     Node(int data){
          this -> data = data;
          this -> next = NULL;
     }

     //destructor
     ~Node(){
          int value = this -> data;
          if(this->next != NULL){
               delete next;
               next = NULL;
          }
          cout << " memory is free for node with data " << value << endl;
     }
};

void insertAtTail(Node* &tail, int d){
    // new node creation
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* reverse(Node* &head){
    if(head == NULL){
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

int main () {
    Node* node1 = new Node(1);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    cout << "Linked list is: ";
    print(head);

    cout << "Reversed Linked list is: ";

    Node* newHead = reverse(head);
    print(newHead);

    cout << endl;

    return 0;
}