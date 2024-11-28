#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

    Trie() {
        root = new TrieNode('\n');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';

        TrieNode* child;

        // present case
        if(root->children[index] != NULL){
            child = root -> children[index];
        }else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }   

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if(root->children[index] != NULL){
            return searchUtil(root->children[index], word.substr(1));
        }else {
            return false;
        }

    }

    void deleteUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else {
            return;
        }

        deleteUtil(child, word.substr(1));
    }

    void deleteWord(string word){
        deleteUtil(root, word);
    }

    void searchWord(string word){
        if(searchUtil(root, word)){
            cout << "The word is present!" << endl;
        }else {
            cout << "The word is not present!" << endl;
        }
    }

    bool prefixUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'A';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else {
            return false;
        }

        return prefixUtil(child, word.substr(1));

    }

    void startWith(string word){
        if(prefixUtil(root, word)){
            cout << "Prefix is present" << endl;
        }else {
            cout << "Prefix is not present" << endl;
        }
    }

};

int main() {

    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    t->searchWord("TIME");

    t->deleteWord("TIME");

    t->searchWord("TIME");

    t->startWith("TIE");

    return 0;
}