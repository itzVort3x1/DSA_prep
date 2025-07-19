#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* root) {

    cout << "Enter data for node: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter left node: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right node: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            cout << endl;
        }else {
            cout << temp ->data << " ";
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(node* root){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout << root-> data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root){
    if(root==NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin>>leftData;
        if(leftData != - 1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin>>rightData;
        if(rightData != - 1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }   

}

int main() {
    node* root = NULL;
    
    // creating a tree;
    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    buildFromLevelOrder(root);

    //level order
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);

    // inorder traversal
    cout << "Inorder traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: " << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: " << endl;
    postorderTraversal(root);

    cout << endl;

    return 0;
}