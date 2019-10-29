#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }

        return dp[m][n];
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str" << endl;
        exit(1);
    }
    string w1 = argv[1], w2 = argv[2];
    Solution s;
    cout << s.minDistance(w1, w2) << endl;

    return 0;
}
