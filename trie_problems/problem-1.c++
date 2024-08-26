//------------------------------------
//      Phone Directory
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
     public:
          char data;
          TrieNode* children[26];
          bool isTerminal;

          TrieNode(char ch){
               data = ch;
               for(int i=0; i<26; i++){
                    children[i] = NULL;
               }
               isTerminal = false;
          }
};

class Trie{
     public:
          TrieNode* root;

     //constructor
     Trie(){
          root = new TrieNode('\0');
     }

     void insertUtil(TrieNode* root, string word){
          if(word.length() == 0){
               root -> isTerminal = true;
               return;
          }
          
          // assume all are lower characters
          int index = word[0] - 'a';
          TrieNode* child;

          if(root -> children[index] != NULL){
               child = root -> children[index];
          }else {
               child = new TrieNode(word[0]);
               root -> children[index] = child;
          }

          insertUtil(child, word.substr(1));
     }

     void insertWord(string word){
          insertUtil(root, word);
     }

     void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
          if(curr -> isTerminal){
               temp.push_back(prefix);
          }

          for(char ch='a'; ch<='z'; ch++){
               TrieNode* next = curr -> children[ch-'a'];
               if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
               }
          }

     }

     void remainingPart(int i, string word, vector<string> &temp, vector<vector<string> > &output){
          for(int k=i; k<word.length(); k++){
               temp.push_back("0");
               output.push_back(temp);
               temp.clear();
          }
          return;
     }

     vector<vector<string> > getSuggestions(string word){
          TrieNode* prev = root;
          vector<vector<string> > output;
          string prefix = "";
          vector<string> temp;

          for(int i=0; i<word.length(); i++){
               char lastch = word[i];
               prefix.push_back(lastch);

               TrieNode* curr = prev -> children[lastch - 'a'];

               if(curr == NULL){
                    // cout << prefix << endl;
                    remainingPart(i, word, temp, output);
                    // temp.push_back("0");
                    // output.push_back(temp);
                    // temp.clear();
                    break;
               }

               printSuggestions(curr, temp, prefix);

               // cout << "Printing temp" << endl;
               // for(int i=0; i<temp.size(); i++){
               //      cout << temp[i] << " ";
               // }
               // cout << "Finished Printing temp" << endl;

               // if(temp.size() == 0){
               //      temp.push_back("0");
               // }

               output.push_back(temp);
               temp.clear();
               prev = curr;

          }

          return output;

     }

};

int main(){
     //search word = "geeips"
     Trie* t = new Trie();

     t->insertWord("joneffenbl");
     t->insertWord("jonggkcg");
     t->insertWord("jonajlkiame");
     t->insertWord("jonkicmdoeoeb");
     t->insertWord("joniogloekjgbjo");
     t->insertWord("jonnjlfoamj");
     t->insertWord("jongndgcckehkk");
     t->insertWord("jonhjj");
     t->insertWord("jonlikfhgkicb");
     t->insertWord("jonjfjcmog");


     vector<vector<string> > output;

     output = t->getSuggestions("jondja");

     for(int i=0; i<output.size(); i++){
          for(int j=0; j<output[i].size(); j++){
               cout << output[i][j] << " ";
          }
          cout << endl;
     }

}