#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if(s[0]=='0')
            return 0;
        
        vector<int>dp (n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int one = stoi(s.substr(i-1,1));
            int two = stoi(s.substr(i-2,2));
            
            if(one>=1) dp[i] += dp[i-1];
            if(two>=10 && two<=26) dp[i] += dp[i-2];
        }
        
        return dp[n];
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify code" << endl;
        exit(0);
    }
    string str = argv[1];
    Solution s;
    cout << s.numDecodings(str) << endl;
    
    return 0;
}
