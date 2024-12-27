//------------------------------------
//      Rearrange characters
//      Link: https://www.geeksforgeeks.org/problems/rearrange-characters4649/1
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int main() {
    string str = "geeksforgeeks";

    int n = str.length();

    unordered_map<char, int> mp;
    priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

    for(char ch:str){
        if(!mp[ch]){
            mp[ch] = 1;
        }else {
            mp[ch]++;
        }
    }

    for(auto i:mp){
        pq.push({i.second, i.first});
    }

    string ans = "";
    pair<int, char> prev = {-1, '#'};

    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();

        ans+=front.second;

        if(prev.first > 0){
            pq.push(prev);
        }

        front.first-=1;
        prev = front;
    }

    if(n != ans.length()){
        cout << "No Possible match found" << endl;
    }else {
        cout << "The resultant string is: " << ans << endl;
    }

    return 0;
}