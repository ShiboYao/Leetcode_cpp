#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (string& w : wordDict)
            set.insert(w);
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i){
            for (int j = i-1; j >= 0; --j){
                if (dp[j] && set.find(s.substr(j, i-j)) != set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};



int main(){
    vector<string> dict{"leet", "code"};
    string str = "leetcode";
    Solution s;
    cout << s.wordBreak(str, dict) << endl;

    return 0;
}
