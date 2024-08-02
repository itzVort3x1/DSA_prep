#include <iostream>
#include <queue>
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

void preOrderTraversal(Node* root){
     if(root == NULL){
          return;
     }

     // NLR
     cout << root -> data << " ";
     preOrderTraversal(root -> left);
     preOrderTraversal(root -> right);
}

void inOrderTraversal(Node* root){
     if(root == NULL){
          return;
     }

     // NLR
     inOrderTraversal(root -> left);
     cout << root -> data << " ";
     inOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
     if(root == NULL){
          return;
     }

     // NLR
     postOrderTraversal(root -> left);
     postOrderTraversal(root -> right);
     cout << root -> data << " ";
}

void levelOrderTraversal(Node* root){
     // base case
     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front == NULL){
               cout << endl;
               if(!q.empty()){
                    q.push(NULL);
               }
          }else {
               cout << front -> data << " ";
               if(front -> left != NULL){
                    q.push(front -> left);
               }
               if(front -> right != NULL){
                    q.push(front -> right);
               }
          }
     }
}

int main()
{
     Node *root = createTree();
     cout << root -> data << endl;
     cout << "Preorder traversal: ";
     preOrderTraversal(root);
     cout << "inOrder traversal" << endl;
     inOrderTraversal(root);
     cout << "postOrder traversal" << endl;
     postOrderTraversal(root);
     cout << "Level order traversal" << endl;
     levelOrderTraversal(root);
     return 0;
}