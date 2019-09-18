#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        int i = 0, j = 0, last_match, star = -1;
        while (i < m){
            if (j < n && s[i] == p[j] || p[j] == '?'){
                i++;
                j++;
            }
            else if (j < n && p[j] == '*'){
                star = j++;
                last_match = i;
            }
            else if (star >= 0){
                j = star + 1;
                i = ++last_match;
            }
            else
                return false;
        }
        while (j < n && p[j] == '*')
            j++;

        return j == n;
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1));
        memo[0][0] = 1;
        for (int j = 1; j <= n; j++)//default of int is 0
            memo[0][j] = (p[j-1] == '*' && memo[0][j-1]);
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (p[j-1] == '*')
                    memo[i][j] = memo[i-1][j] || memo[i][j-1];
                else if (p[j-1] == '?' || p[j-1] == s[i-1])
                    memo[i][j] = memo[i-1][j-1];
            }
        }

        return memo.back().back();
    }
};
*/


int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify str1 and str2" << endl;
        exit(1);
    }
    string str1 = argv[1], str2 = argv[2];
    Solution s;
    cout << s.isMatch(str1, str2) << endl;

    return 0;
}
