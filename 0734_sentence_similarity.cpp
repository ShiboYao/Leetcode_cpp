#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int m = words1.size(), n = words2.size();
        if (m != n) return false;
        unordered_map<string, unordered_set<string>> mp;
        for (vector<string>& p : pairs){
            if (mp.find(p[0]) == mp.end())
                mp[p[0]] = unordered_set<string>{};
            mp[p[0]].insert(p[1]);
            if (mp.find(p[1]) == mp.end())
                mp[p[1]] = unordered_set<string>{};
            mp[p[1]].insert(p[0]);
        }
        int i = 0;
        while (i < n){
            if (words1[i] != words2[i] && mp[words1[i]].find(words2[i]) == mp[words1[i]].end())
                return false;
            i++;
        }

        return true;
    }
};



int main(){
    vector<string> words1{"great", "acting", "skills"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs{{"great","fine"},{"acting","drama"},{"skills","talent"}};
    Solution s;
    cout << s.areSentencesSimilar(words1, words2, pairs) << endl;

    return 0;
}
