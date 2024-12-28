//------------------------------------
//      Parenthesis Checker
//      Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
//------------------------------------

#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s = "{([])}";

    stack<char> st;

    for(int i = 0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else {
            if(!st.empty()){
                char top = st.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    st.pop();
                }else {
                    cout << "Invalid parenthesis" << endl;
                    return 0;
                }
            }else {
                cout << "Invalid parenthesis" << endl;
                return 0;
            }
        }
    }

    if(!st.empty()){
        cout << "Invalid parenthesis" << endl;
    }else {
        cout << "Valid parenthesis" << endl;
    }

    return 0;
}