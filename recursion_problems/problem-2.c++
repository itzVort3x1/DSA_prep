//------------------------------------
//      Check if the string is palindrome or not
//      Ex: INPUT: str = abba
//          OUTPUT: true
//------------------------------------

#include<iostream>

using namespace std;

bool checkPalindrome(string str, int i, int j){
    if(i>j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }else {
        return checkPalindrome(str, i+1, j-1);
    }
}

int main(){
    string s = "abba";

    if(checkPalindrome(s, 0, s.length()-1)){
        cout<<"The string is a palindrome"<<endl;
    }else{
        cout<<"The string is not palindrome"<<endl;
    }
}