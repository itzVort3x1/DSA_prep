//------------------------------------
//       LONGEST COMMON PREFIX
//------------------------------------

#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int count;
        bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        count = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else {
            child = new TrieNode(word[0]);
            root->count++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string first, string &ans){
        for(int i =0; i<first.length(); i++){
            char ch = first[i];

            if(root->count == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }else {
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }

};

int main(){

    Trie* t = new Trie();

    t->insertWord("cater"); 
    t->insertWord("care"); 
    t->insertWord("cam"); 
    t->insertWord("caver"); 
    t->insertWord("caved"); 
    t->insertWord("caad"); 
    t->insertWord("cav"); 
    t->insertWord("cat"); 
    t->insertWord("cat"); 
    t->insertWord("car"); 

    string first = "car";
    string ans = "";

    t->lcp(first, ans);

    cout << "The longest common prefix is: " << ans << endl;

    return 0;
}