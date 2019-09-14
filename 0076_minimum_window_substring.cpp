#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        string r = "";
        unordered_map<char, int> mp;
        int m = t.size(), n = s.size();
        for (char c : t)
            mp[c]++;
        int start = 0, mini = n+1;
        int i = 0, j = 0, count = 0;
        while (j < n){
            while (j < n && count < m){
                if (mp.find(s[j]) != mp.end()){
                    mp[s[j]]--;
                    if (mp[s[j]] >= 0)
                        count++;
                }
                j++;
            }
            while (count == m){
                if (mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count--;
                }
                i++;
            }
            if (mini > j-i+1){
                start = i-1;
                mini = j-i+1;
            }
        }
        if (mini < n+1)
            r = s.substr(start, mini);

        return r;
    }
};



int main(){
    string s = "a", t = "aa";
    Solution so;
    cout << so.minWindow(s, t) << endl;

    return 0;
}
