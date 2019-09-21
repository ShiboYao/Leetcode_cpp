#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> r;
        for (auto& m : mp)
            r.push_back(m.second);

        return r;
    }
};



int main(){
    vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> r = s.groupAnagrams(a);
    for (vector<string>& i : r){
        for (string& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
