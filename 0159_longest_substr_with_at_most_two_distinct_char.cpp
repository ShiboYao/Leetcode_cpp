#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = 0, n = s.size(), maxi = 0;
        unordered_map<char,int> mp;
        while (i < n){
            if (mp.size() <= 2)
                mp[s[i++]]++;
            else{
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    mp.erase(s[j]);
                j++;
            }
            if (mp.size() <= 2)
                maxi = max(maxi, i-j);
        }

        return maxi;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.lengthOfLongestSubstringTwoDistinct(str) << endl;

    return 0;
}
