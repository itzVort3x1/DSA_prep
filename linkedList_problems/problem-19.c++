//------------------------------------
//        Check if the linked list is palindrome or not - APPROACH - 1
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

vector<int> createArray(Node* &head){
     vector<int> arr;

     Node* temp = head;
     while(temp != NULL){
          arr.push_back(temp -> data);
          temp = temp -> next;
     }

     return arr;
}

bool isPalindrome(vector<int> arr){
     int n = arr.size();
     int s = 0;
     int e = n-1;

     while(s<=e){
          if(arr[s] != arr[e]){
               return false;
          }
          s++;
          e--;
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

     vector<int> arr = createArray(head);
     if(isPalindrome(arr)){
          cout << "The given linked list is palindrome" << endl;
     }else {
          cout << "The given linked list is not palindrome" << endl;
     }
}