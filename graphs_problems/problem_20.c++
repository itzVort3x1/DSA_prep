//------------------------------------
//      Number of Island's 
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j) {
    if(i <0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] == '0'){
        return;
    }

    grid[i][j] = '0';

    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid,i,j+1);
    dfs(grid, i, j-1);

}

int main() {

    vector<vector<char>> grid = {{'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}};

    if(grid.empty()) {
        cout << "The grid is empty: " << endl;
    }

    int num_islands = 0;

    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                num_islands++;
                dfs(grid,i,j);
            }
        }
    }

    cout << "Total Number of islands are: " << num_islands << endl;

    return 0;
}
