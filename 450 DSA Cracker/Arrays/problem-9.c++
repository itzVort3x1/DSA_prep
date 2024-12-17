//------------------------------------
//      Minimum Jumps
//      Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {1,3,5,8,92,6,7,6,8,9};

    if(arr[0] == 0){
        cout << "The minimum jumps is: " << -1 << endl;
        return 0;
    }

    int ans = 1;
    int jump = arr[0];
    int mx = 0;
    for(int i = 1; i<arr.size(); i++){
        mx--;
        jump--;
        mx = max(mx, arr[i]);

        if(!jump && i != arr.size() - 1){
            if(mx <= 0) return -1;
            jump = mx;
            mx = 0;
            ans++;
        }
    }

    cout << "The minimum jumps required is: " << ans << endl;
    return 0;
}