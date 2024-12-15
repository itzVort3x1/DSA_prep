//------------------------------------
//      Circular Sentence
//      Link: https://leetcode.com/problems/circular-sentence/description/
//------------------------------------

#include <iostream>
using namespace std;

int main() {
    string sentence = "leetcode exercises sound delightful";
    
    if(sentence[0] != sentence[sentence.length() - 1]){
        cout << "The string is not a circular sentence" << endl;
        return 0;
    }

    for(int i = 1; i < sentence.length(); i++){
        if(sentence[i] == ' ' && (sentence[i-1] != sentence[i+1])){
            cout << "The string is not a circular sentence" << endl;
            return 0;
        }
    }

    cout << "The string is a circular sentence" << endl;

    return 0;

}