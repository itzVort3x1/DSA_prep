//------------------------------------
//        Print the bottom view of binary tree
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

void printBottomView(Node* root){
     map<int, int> hdToNodemap;

     queue< pair<Node*,int> > q;

     q.push(make_pair(root, 0));

     while(!q.empty()){
          pair<Node*, int> temp = q.front();
          q.pop();

          Node* frontNode = temp.first;
          int hd = temp.second;

          hdToNodemap[hd] = frontNode->data;

          if(frontNode->left != NULL){
               q.push(make_pair(frontNode->left, hd-1));
          }
          if(frontNode->right != NULL){
               q.push(make_pair(frontNode->right, hd+1));
          }
     }

     cout << "Printing top view: " << endl;
     for(auto i:hdToNodemap){
          cout << i.second << " ";
     }

}

int main() {
     Node* root = createTree();
     // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
     levelOrderTraversal(root);

     printBottomView(root);
     return 0;
}