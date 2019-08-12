#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();

        int left = 0, right = 0;
        vector<bool> hash(128, false);
        int longest = 0;
        while (right < s.size()){
            while (right < s.size() && !hash[s[right]]){
                hash[s[right]] = true;
                right++;
            }
            longest = max(longest, right-left);
            if (hash[s[right]]){
                while (s[left] != s[right]){
                    hash[s[left]] = false;
                    left++;
                }
                left++;
                right++;
            }
        }

        return longest;
    }
};


int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify a string" << endl;
        exit(1);
    }
    string s = argv[1];
    cout << s << endl;
    cout << s.size() << endl;
    Solution S;
    int longest = S.lengthOfLongestSubstring(s);
    cout << longest << endl;

    return 0;
}
