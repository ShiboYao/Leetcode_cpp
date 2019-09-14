#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cur(26,0), goal(26,0);
        for (char c: s1)
            goal[c - 'a']++;
        int i = 0, n = s2.size(), m = s1.size();
        while (i < n){
            cur[s2[i] - 'a']++;
            if (i >= m)
                cur[s2[i - m] - 'a']--;
            if (cur == goal)
                return true;
            i++;
        }

        return false;
    }
};



int main(){
    string s1 = "ad", s2 = "eidbsaooo";
    Solution s;
    cout << s.checkInclusion(s1, s2) << endl;

    return 0;
}
