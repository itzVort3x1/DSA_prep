//------------------------------------
//      Check if string is palindrome or not.
//      Ex: INPUT: n = NOON
//          OUTPUT: True
//------------------------------------

#include<iostream>

using namespace std;

bool checkPalindrome(char a[], int n){
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        if(a[s] != a[e]){
            return 0;
        }else {
            s++;
            e--;
        }
    }
    return 1;
}

int getLength(char name[]){
    int count=0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }

    return count;
}

int main(){
    char name[20];

    cout<<"Enter a string: ";
    cin>>name;

    if(checkPalindrome(name,getLength(name))){
        cout<<"The given string is palindrome."<<endl;
    }else{
        cout<<"The given string is not palindrome."<<endl;
    }

    return 0;

}