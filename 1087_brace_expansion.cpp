#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void util(vector<vector<char>>& s, int i, string cur, vector<string>& r){
        if (i == s.size()){
            r.push_back(cur);
            return;
        }
        for (char c : s[i])
            util(s, i+1, cur+c, r);
    }

    vector<string> expand(string S) {
        vector<vector<char>> s{vector<char>{}};
        int i = 0, n = S.size();
        while (i < n){
            if (S[i] == '{'){
                while (S[i] != '}'){
                    if (isalpha(S[i]))
                        s.back().push_back(S[i]);
                    i++;
                }
                sort(s.back().begin(), s.back().end());
            }
            else 
                s.back().push_back(S[i]);
            if (++i < n)
                s.push_back(vector<char>{});
        }
        vector<string> r;
        util(s, 0, "", r);

        return r;    
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    vector<string> r = s.expand(str);
    for (string& i : r)
        cout << i << endl;

    return 0;
}
