#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j){
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] <= 0)
            return 0;
        g[i][j] = -g[i][j];
        int t = max(max(dfs(g,i-1,j),dfs(g,i+1,j)),max(dfs(g,i,j-1),dfs(g,i,j+1)));
        g[i][j] = -g[i][j];

        return g[i][j] + t;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                maxi = max(maxi, dfs(grid,i,j));
            }
        }

        return maxi;
    }
};



int main(){
    //vector<vector<int>> a{{0,6,0},{5,8,7},{0,9,0}};
    //vector<vector<int>> a{{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    vector<vector<int>> a{{1,0,7,0,0,0},{2,0,6,0,1,0},{3,5,6,7,4,2},{4,3,1,0,2,0},{3,0,5,0,20,0}};
    Solution s;
    cout << s.getMaximumGold(a) << endl;

    return 0;
}
