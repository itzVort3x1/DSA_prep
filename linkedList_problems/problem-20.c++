//------------------------------------
//        Check if the linked list is palindrome or not - APPROACH - 2
//------------------------------------

#include<iostream>
#include<vector>
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

Node* getMid(Node* head){
     Node* slow = head;
     Node* fast = head -> next;

     while(fast != NULL){
          fast = fast -> next;
          if(fast != NULL){
               fast = fast -> next;
          }
          slow = slow -> next;
     };
     return slow;
}

Node* reverseList(Node* head){
     Node* curr = head;
     Node* prev = NULL;
     Node* next = NULL;

     while(curr != NULL){
          next = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = next;
     }
     return prev;
}

bool isPalindrom(Node* head, Node* mid){
     while(head != mid && mid != NULL){
          if(head -> data == mid -> data){
               head = head -> next;
               mid = mid -> next;
          }else {
               return false;
          }
     }
     return true;
}

int main(){
     Node* node1 = new Node(5);
     Node* head = node1;

     InserAtHead(head, 4);
     InserAtHead(head, 3);
     InserAtHead(head, 4);
     InserAtHead(head, 5);
     Print(head);

     Node* middle = getMid(head);
     cout << "The middle of the linked list is: " << middle -> data << endl;
     Node* temp = middle -> next;
     middle -> next = reverseList(temp);

     //step-3
     if(isPalindrom(head, middle -> next)){
          cout << "The given list is palindrome" << endl;
     }else {
          cout << "The given list is not palindrome" << endl;
     }

     cout << "List after Checking for palindrome: " << endl;
     Print(head);
     temp = middle -> next;
     middle -> next = reverseList(temp);

     cout << "Original List: " << endl;
     Print(head);

}