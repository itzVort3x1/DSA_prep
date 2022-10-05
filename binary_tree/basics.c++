#include<iostream>
#include<queue>
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

Node* buildTree(Node* root){
     cout << "Enter the data for node: " << endl;
     int data;
     cin >> data;
     root = new Node(data);

     if(data == -1){
          return NULL;
     }

     cout << "Enter data for inserting at left of " << data << endl;
     root -> left = buildTree(root -> left);
     cout << "Enter data for inserting at right of " << data << endl;
     root -> right = buildTree(root -> right);
     return root;
}

void levelOrderTraversal(Node* root){
     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
          Node* temp = q.front();
          q.pop();

          if(temp == NULL){
               // if temp = null previous level done
               cout << endl;
               if(!q.empty()){
                    q.push(NULL);
               }
          }else {
               cout << temp -> data << " ";

               if(temp -> left){
                    q.push(temp -> left);
               }

               if(temp -> right){
                    q.push(temp -> right);
               }
          }
     }
}

void inorder(Node* root){
     //base case
     if(root == NULL){
          return;
     }

     inorder(root -> left);
     cout << root -> data << " ";
     inorder(root -> right);

}

void preorder(Node* root){
     //base case
     if(root == NULL){
          return;
     }

     cout << root -> data << " ";
     preorder(root -> left);
     preorder(root -> right);
}

void postorder(Node* root){
     //base case
     if(root == NULL){
          return;
     }

     postorder(root -> left);
     postorder(root -> right);
     cout << root -> data << " ";
}

int main(){

     Node* root = NULL;

     //creating a tree;
     //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     root = buildTree(root);

     cout<< "Printing the level order traversal output " << endl;
     levelOrderTraversal(root);

     cout << "Inorder Traversal is: " << endl;
     inorder(root);

     cout << "Preorder Traversal is: " << endl;
     preorder(root);

     cout << "Postorder Traversal is: " << endl;
     postorder(root);

     return 0;
}