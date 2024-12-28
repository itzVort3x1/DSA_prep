//------------------------------------
//      Count and Say
//      Link: https://leetcode.com/problems/count-and-say/description/
//------------------------------------

#include<iostream>
#include<string>
using namespace std;


string countAndSay(int n){
    if(n == 1) return "1";

    string say = countAndSay(n - 1);

    string result = "";

    for(int i = 0; i<say.length(); i++){
        char ch = say[i];
        int count = 1;

        while(i < say.length() - 1 && say[i] == say[i+1]){
            count++;
            i++;
        }

        result += to_string(count) + string(1, ch);
    }

    return result;
}

int main() {
    int n = 10;

    string res = countAndSay(n);

    cout << "The compressed string is: " << res << endl;

    return 0;
}