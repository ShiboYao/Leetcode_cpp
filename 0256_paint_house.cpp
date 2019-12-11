#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (!n) return 0;
        vector<vector<int>> dp(n,vector<int>(3));
        for (int i = 0; i < 3; i++)
            dp[0][i] = costs[0][i];
        for (int i = 1; i < n; i++){
            dp[i][0] = costs[i][0] + min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0],dp[i-1][1]);
        }

        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};



int main(){
    vector<vector<int>> a{{17,2,17},{16,16,5},{14,3,19}};
    Solution s;
    cout << s.minCost(a) << endl;

    return 0;
}
