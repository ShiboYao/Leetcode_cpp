#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    count += (i == 0 || grid[i-1][j] == 0);
                    count += (i == m-1 || grid[i+1][j] == 0);
                    count += (j == 0 || grid[i][j-1] == 0);
                    count += (j == n-1 || grid[i][j+1] == 0);
                }
            }
        }

        return count;
    }
};



int main(){
    vector<vector<int>> a{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution s;
    cout << s.islandPerimeter(a) << endl;

    return 0;
}
