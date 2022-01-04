//------------------------------------
//      Max occuring character
//      Ex: INPUT: n = 
//          OUTPUT: 
//------------------------------------

#include<iostream>

using namespace std;

char getMaxOccCharacter(string s){
    int arr[26] = {0};

    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        int number = 0;
        // case to handle lower case
        if(ch>='a' && ch<='z'){
            number = ch - 'a';
        }else {
            // case to handle upper case
            number = ch-'A';
        }
        arr[number]++;
    }

    int maxi = -1;
    int ans = 0;
    for(int i=0; i<26; i++){
        if(maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    return 'a' + ans;
}

int main(){
    string s;

    cin>>s;

    cout<<getMaxOccCharacter(s)<<endl;

    return 0;
}