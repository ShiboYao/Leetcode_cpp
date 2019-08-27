#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void util(vector<string>& r, vector<string> dic, string s, int pos, string digits){
        if (s.size() == digits.size()){
            r.push_back(s);
            return;
        }
        int a = digits[pos] - '0' - 2;
        for (int i = 0; i < dic[a].size(); i++)
            util(r, dic, s+dic[a][i], pos+1, digits);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> r;
        if (digits.empty())
            return r;
        vector<string> dic{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        util(r, dic, "", 0, digits);

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    vector<string> r = s.letterCombinations(str);
    for (string& i : r)
        cout << i << endl;

    return 0;
}
