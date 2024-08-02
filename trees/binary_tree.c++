#include <iostream>
using namespace std;

class Node{
     public:
          int data;
          Node* left;
          Node* right;

          Node(int d){
               this -> data = d;
               this -> left = NULL;
               this -> right = NULL;
          }   
};

Node* createTree(){
     cout << "enter the value for Node: " << endl;
     int data;
     cin >> data;

     if(data == -1){
          return NULL;
     }

     // Step1; create node
     Node* root = new Node(data);
     // Step2: create left subtree
     cout << "left of Node: " << root ->data<<endl;
     root -> left = createTree();
     //step3: create right subtree
     cout << "right of Node: " << root -> data << endl;
     root -> right = createTree();

     return root;
};

int main()
{
     Node *root = createTree();
     cout << root -> data << endl;

     return 0;
}