#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    void util(vector<vector<int>>& r, vector<int> cur, int pos, vector<int> candidates, int target){
        if (target == 0){
            r.push_back(cur);
            return;
        }
        if (target < 0)
            return;
        for (int i = pos; i < candidates.size(); i++){
            if (candidates[i] > target)
                return;
            cur.push_back(candidates[i]);
            util(r, cur, i, candidates, target-candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> r;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        util(r, cur, 0, candidates, target);

        return r;
    }
};



int main(){
    vector<int> a{2,3,6,7};
    int target = 7;
    Solution s;
    vector<vector<int>> r = s.combinationSum(a, target);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
