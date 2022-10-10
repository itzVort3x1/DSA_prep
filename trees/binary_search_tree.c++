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

Node* insertIntoBST(Node* root, int data){
     // base case
     if(root == NULL){
          root = new Node(data);
          return root;
     }

     if(data > root -> data){
          root  -> right = insertIntoBST(root -> right, data);
     }else {
          root -> left  = insertIntoBST(root -> left, data);
     }

     return root;

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


void takeInput(Node* &root){
     int data;
     cin >> data;

     while(data != -1){
          root = insertIntoBST(root, data);
          cin >> data;
     }
}

int main(){
     Node* root = NULL;

     cout << "Enter data to create BST" << endl;

     takeInput(root);

     levelOrderTraversal(root);

     return 0;
}