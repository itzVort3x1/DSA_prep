//------------------------------------
//      Given inOrder and preOrder create a tree
//------------------------------------

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

int searchInOrder(int inorder[], int size, int target){
     for(int i = 0; i<size; i++){
          if(inorder[i] == target){
               return i;
          }
     }

     return -1;
}

Node* constructTreeFromPreAndInorderTraversal(int preorder[], int inorder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
     //base case
     if(preIndex >= size || inOrderStart > inOrderEnd){
          return NULL;
     }

     int element = preorder[preIndex];
     preIndex++;
     Node* root = new Node(element);
     // element search
     int position = searchInOrder(inorder, size, element);

     root->left = constructTreeFromPreAndInorderTraversal(preorder, inorder, preIndex, inOrderStart, position - 1, size);

     root->right = constructTreeFromPreAndInorderTraversal(preorder, inorder, preIndex, position + 1, inOrderEnd, size);

     return root;
}

int main() {
     int inorder[] = {10,8,6,2,4,12};
     int preorder[] = {2,8,10,6,4,12};
     int size = 6;
     int preOrderIndex = 0;
     int inorderStart = 0;
     int inorderEnd = 5;

     Node* root = constructTreeFromPreAndInorderTraversal(preorder, inorder, preOrderIndex, inorderStart, inorderEnd, size);

     cout << "Printing the root of the tree: " << root -> data << endl;

     return 0;
}