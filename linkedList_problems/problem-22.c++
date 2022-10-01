//------------------------------------
//        Merge sort on linked list
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
     while(head != NULL){
          cout << head -> data << " ";
          head = head -> next;
     }
     cout << endl;
}

void InsertAtTail(Node* &head, Node* &tail, int value){
     Node* temp = new Node(value);
     // empty list case
     if(head == NULL){
          head = temp;
          tail = temp;
          return;
     }else {
          tail -> next = temp;
          tail = temp;
     }
}

Node* findMid(Node* &head){
     Node* slow = head;
     Node* fast = head -> next;

     while(fast != NULL && fast -> next != NULL){
          slow = slow -> next;
          fast = fast -> next -> next;
     }
     return slow;
}

Node* merge(Node* left, Node* right){

     if(left == NULL){
          return right;
     }

     if(right == NULL){
          return left;
     }

     Node* ans = new Node(-1);
     Node* temp = ans;

     while(left != NULL && right != NULL){
          if(left -> data < right -> data){
               temp -> next = left;
               temp = left;
               left = left -> next;
          }else {
               temp -> next = right;
               temp = right;
               right = right -> next;
          }
     }

     while(left != NULL){
          temp -> next = left;
          temp = left;
          left = left -> next;
     }

     while(right != NULL){
          temp -> next = right;
          temp = right;
          right = right -> next;
     }

     return ans -> next;

}

Node* mergeSort(Node* &head){
     if(head == NULL || head -> next == NULL){
          return head;
     }

     Node* mid = findMid(head);

     Node* left = head;
     Node* right = mid -> next;
     mid -> next = NULL;

     left = mergeSort(left);
     right = mergeSort(right);

     //merge both left and right halfs
     Node* result = merge(left, right);

     return result; 

}

int main(){
     Node* head = NULL;
     Node* tail = NULL;
     InsertAtTail(head, tail, 1);
     InsertAtTail(head, tail, 4);
     InsertAtTail(head, tail, 5);
     InsertAtTail(head, tail, 2);

     cout << "Unsorted array: ";
     Print(head);

     cout << "Sorted Array: ";
     Print(mergeSort(head));

}