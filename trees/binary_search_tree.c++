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

NOde* maxVal(Node* root){
     if(root == NULL){
          return root;
     }

     Node* temp = root;
     while(temp->right != NULL){
          temp = temp -> right;
     }

     return temp;
}

Node* minVal(Node* root){
     if(root == NULL){
        return root;
    }
    
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* deleteFromBst(Node* root, int val){
     if(root == NULL){
          return root;
     }

     if(root -> data == val){
          //0 child

          if(root -> left == NULL && root -> right == NULL){
               delete root;
               return NULL;
          }

          //1 child
          //left child
          if(root -> left != NULL && root -> right == NULL){
               Node* temp = root -> left;
               delete root;
               return temp;
          }
          if(root -> left == NULL && root -> right != NULL){
               Node* temp = root -> right;
               delete root;
               return temp;
          }
          //2 child
          if(root -> left != NULL && root -> right != NULL){
               int mini = minVal(root -> right) -> data;
               root -> data = mini;
               root -> right = deleteFromBst(root -> right, mini);
               return root;
          }


     }else if(root -> data > val){
          root -> left = deleteFromBst(root -> left, val);
          return root;
     }else {
          root -> right = deleteFromBst(root -> right, val);
          return root;
     }

}

int main(){
     Node* root = NULL;

     cout << "Enter data to create BST" << endl;

     takeInput(root);

     levelOrderTraversal(root);

     root = deleteFromBst(root, 30);

     levelOrderTraversal(root);

     return 0;
}