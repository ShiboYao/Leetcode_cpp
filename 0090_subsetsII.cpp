#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> r;
        if (nums.empty())
            return r;
        r.push_back({});
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        for (auto& i : mp){
            int n = r.size();
            while (i.second > 0){
                for (int j = 0; j < n; j++){
                    r.push_back(r[j]);
                    r[j].push_back(i.first);
                }
                i.second--;
            }
        }

        return r;
    }
};


int main(){
    vector<int> a{1,2,2};
    Solution s;
    vector<vector<int>> r = s.subsetsWithDup(a);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
