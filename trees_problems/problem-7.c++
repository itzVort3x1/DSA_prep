//------------------------------------
//        Given inorder create a BST
//------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
     public:
          int data;
          Node* left;
          Node* right;

          Node(int val){
               this->data = val;
               this->left = NULL;
               this->right = NULL;
          };
};

void preOrder(Node* root){
     if(root == NULL){
          return;
     }

     cout << root-> data << " ";
     preOrder(root->left);
     preOrder(root->right);
}

void inOrder(Node* root){
     if(root == NULL){
          return;
     }

     inOrder(root->left);
     cout << root-> data << " ";
     inOrder(root->right);
}

void postOrder(Node* root){
     if(root == NULL){
          return;
     }

     postOrder(root->left);
     postOrder(root->right);
     cout << root-> data << " ";
}

Node* createTree(){
     cout << "Enter the value for the Node: ";
     int value;
     cin >> value;

     if(value == -1){
          return NULL;
     }

     Node* root = new Node(value);
     cout << "Enter in left of: " << value << endl;
     root -> left = createTree();
     cout << "Enter in right of: " << value << endl;
     root -> right = createTree();
}

void levelOrderTraversal(Node* root){
     queue<Node*> q;

     q.push(root);
     q.push(NULL);
     cout << endl;
     while(!q.empty()){
          Node* temp = q.front();
          q.pop();

          if(temp == NULL){
               cout << endl;
               if(!q.empty()){
                    q.push(NULL);
               }
          }else {
               cout << temp->data << " ";
               if(temp->left != NULL){
                    q.push(temp->left);
               }

               if(temp->right != NULL){
                    q.push(temp->right);
               }
          }
     }
}

void printLeftBoundary(Node* root){
     if(root == NULL){
          return;
     }

     if(root->left == NULL && root->right == NULL){
          return;
     }

     cout << root->data<<" ";
     if(root->left != NULL){
          printLeftBoundary(root->left);
     }else {
          printLeftBoundary(root->right);
     }
}

void printLeafBoundary(Node* root){
     if(root == NULL){
          return;
     }

     if(root->left == NULL && root->right == NULL){
          cout << root->data << " ";
     }

     printLeafBoundary(root->left);
     printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
     if(root == NULL){
          return;
     }

     if(root->left == NULL && root->right == NULL){
          return;
     }

     if(root->right != NULL){
          printRightBoundary(root->right);
     }else {
          printRightBoundary(root->left);
     }
     cout << root->data<<" ";
}

void boundaryTraversal(Node* root){
     if(root == NULL){
          return;
     }

     cout << root->data << " ";
     printLeftBoundary(root->left);
     printLeafBoundary(root);
     printRightBoundary(root->right);
}

Node* bstFromInorder(int inorder[], int s, int e){
     if(s > e){
          return NULL;
     }

     int mid = s + (e-s) / 2;
     int element = inorder[mid];
     Node* root = new Node(element);

     root->left = bstFromInorder(inorder, s, mid - 1);
     root->right = bstFromInorder(inorder, mid + 1, e);

     return root;
}

int main() {
     // Node* root = createTree();
     // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

     int inorder[] = {10,20,30,40,50,60,70};
     int size = 7;
     int start = 0;
     int end = size - 1;
     Node* root = bstFromInorder(inorder, start, end);
     levelOrderTraversal(root);
     return 0;
}