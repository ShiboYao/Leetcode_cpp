#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, string& cur){
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c]){
            grid[r][c] = 0;
            cur += to_string(r-i) + to_string(c-j);
            dfs(grid, i, j, r-1, c, cur);
            dfs(grid, i, j, r+1, c, cur);
            dfs(grid, i, j, r, c-1, cur);
            dfs(grid, i, j, r, c+1, cur);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        unordered_set<string> set;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]){
                    string cur;
                    dfs(grid, i, j, i, j, cur);
                    set.insert(cur);
                }
            }
        }

        return set.size();
    }
};



int main(){
    vector<vector<int>> a{{1,1,0,0,0}, {1,1,0,0,0}, {0,0,0,1,1}, {0,0,0,1,1}};
    Solution s;
    cout << s.numDistinctIslands(a) << endl;

    return 0;
}
