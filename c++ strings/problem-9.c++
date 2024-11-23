#include<iostream>
#include<unordered_map>
using namespace std;


int main() {
    string s = "MCMXCIV";

    unordered_map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int sum = 0;
    int preVal = 0;

    for(int i = s.size() - 1; i >= 0; i--){
        int currVal = m[s[i]];

        if(currVal < preVal){
            sum -= currVal;
        }else {
            sum += currVal;
        }

        preVal = currVal;
    }

    cout << sum << endl;

    return 0;
}