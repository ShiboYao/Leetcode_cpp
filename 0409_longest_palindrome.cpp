#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(128);
        int count = 0;
        for (char c : s)
            mp[c-'A']++;
        bool single = false;
        for (int i : mp){
            if (i > 0){
                if (i % 2){
                    single = true;
                    count += i-1;
                }
                else
                    count += i;
            }
        }

        return count+single;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.longestPalindrome(str) << endl;

    return 0;
}
