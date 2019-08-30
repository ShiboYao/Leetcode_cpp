#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1'){
            grid[i][j] = '0';
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};



int main(){
    vector<vector<char>> c = {{'1','1','1'}, {'0','1','0'}, {'1','0','0'}};
    Solution s;
    cout << s.numIslands(c) << endl;

    return 0;
}
