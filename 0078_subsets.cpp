#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        if (nums.empty())
            return r;
        r.push_back({});
        for (int i = 0; i < nums.size(); i++){
            int n = r.size();
            for (int j = 0; j < n; j++){
                r.push_back(r[j]);
                r[j].push_back(nums[i]);
            }
        }

        return r;
    }
};



int main(){
    vector<int> a{1,2,3};
    Solution s;
    vector<vector<int>> r = s.subsets(a);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
