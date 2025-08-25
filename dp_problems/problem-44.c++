//------------------------------------
//      Decode ways
//------------------------------------


#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s = "226";

    if(s.empty() || s[0] == '0') {
        cout << "Number of possible combinations is: " << 0 << endl;
        return 0;
    }

    int n = s.length();

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++) {
        int oneDigit = s[i-1] - '0';
        int twoDigits = stoi(s.substr(i-2, 2));

        if(oneDigit != 0) {
            dp[i] += dp[i-1];
        }

        if(10 <= twoDigits && twoDigits <= 26) {
            dp[i] += dp[i-2];
        }
    }

    cout << "Number of possible combinations is: " << dp[n] << endl;

    return 0;
}
