#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            for(int i = 0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

// insertion
void insertWord(TrieNode* root, string word){
     // cout << "recieved word: " << word << " for insertion " << endl;
     if(word.length() == 0){
          root->isTerminal = true;
          return;
     }

     char ch = word[0];
     int index = ch - 'a';

     TrieNode* child;
     if(root->children[index]!= NULL){
          // present
          child = root->children[index];
     }else {
          // absent
          child = new TrieNode(ch);
          root->children[index] = child;
     }

     // recursion
     insertWord(child, word.substr(1)); 
};

bool searchWord(TrieNode* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }

    int index = word[0] - 'a';

    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }else {
        return false;
    }

    return searchWord(child, word.substr(1));
};

void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    int index = word[0] - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }else {
        return;
    }

    deleteWord(child, word.substr(1));
}

int main() {

    TrieNode* root = new TrieNode('-');

    insertWord(root, "abcd");
    insertWord(root, "aksjd");

    cout << "Present or not: " << searchWord(root, "abcd") << endl;

    deleteWord(root, "abcd");

    cout << "Present or not: " << searchWord(root, "abcd") << endl;

    return 0;
}