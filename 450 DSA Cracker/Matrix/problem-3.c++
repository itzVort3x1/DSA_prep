//------------------------------------
//      Row with max 1s
//      Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
//------------------------------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    vector<vector<int>> arr = {{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};

    int n = arr.size();
    int m = arr[0].size();
    int rowCount = -1;
    int oneCount = INT_MIN;
    
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 1){
                count++;
            }
        }
        if(count != 0 && (count > oneCount)){
            rowCount = i;
            oneCount = count;
        }
    }
    
    cout << "The row with max 1's is: " << rowCount << endl;

    return 0;
}