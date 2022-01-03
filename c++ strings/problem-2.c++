//------------------------------------
//      Reverse a string.
//      Ex: INPUT: n = hello
//          OUTPUT: olleh
//------------------------------------

#include<iostream>

using namespace std;

void getReverse(char name[], int n){
    int s=0; 
    int e=n-1;

    while(s<e){
        swap(name[s++], name[e--]);
    }
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

    cout<<"Enter name: ";
    cin>>name;

    cout<<"The entered name is: "<<name<<endl;

    int n = getLength(name);

    getReverse(name, n);
    cout<<"The reverse name is: "<<name<<endl;

    return 0;
}