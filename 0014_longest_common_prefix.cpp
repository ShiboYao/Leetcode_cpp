#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        while (true){
            for (int j = 1; j < n; j++){
                if (i == strs[j].size() || strs[j][i] != strs[j-1][i])
                    return strs[j].substr(0,i);
            }
            ++i;
        }

        return "";
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify strs" << endl;
        exit(1);
    }
    vector<string> strs;
    for (int i = 1; i < argc; i++)
        strs.push_back(argv[i]);
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}
