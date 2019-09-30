#include <iostream>
using namespace std;


class Solution {
public:
    void util(string& s, int i, int j, int& count){
        if (i < 0 || j == s.size() || s[i] != s[j])
            return;
        count++;
        util(s, i-1, j+1, count);
    }

    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            util(s, i, i+1, count);
            util(s, i, i, count);
        }

        return count;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.countSubstrings(str) << endl;

    return 0;
}
