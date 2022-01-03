//------------------------------------
//      Convert string to lower case.
//      Ex: INPUT: n = HELLO
//          OUTPUT: hello
//------------------------------------

#include<iostream>

using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main(){
    char name[20];

    cout<<"Enter a String: ";
    cin>>name;

    cout<<"The entered string is: "<<name<<endl;
    for(int i=0; name[i]!='\0'; i++){
        name[i] = toLowerCase(name[i]);
    }

    cout<<"The String to lower case is: "<<name;
}