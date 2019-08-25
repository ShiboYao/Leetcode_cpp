#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp; 
        int max_len = 0;
        int i = 0, j = 0;
        while (j < s.size()){
            mp[s[j]]++;
            while (mp.size() > k){
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            max_len = max(max_len, j-i+1);
            j++;
        }
        
        return max_len;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify string and length" << endl;
        exit(1);
    }
    string str = argv[1];
    int k = argv[2][0] - '0';
    Solution s;
    cout << s.lengthOfLongestSubstringKDistinct(str, k) << endl;

    return 0;
}
