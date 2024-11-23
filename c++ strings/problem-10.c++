#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {

    vector<pair<int, string>> romanMap = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    int num = 58;

    string result = "";

    for(const auto &pair: romanMap){
        while(num >= pair.first){
            result += pair.second;
            num -= pair.first;
        }
    }

    cout << result << endl;

    return 0;
}