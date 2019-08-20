#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    void DFS(vector<int>& nums, vector<vector<int>>& r, int pos){
        if (pos == nums.size()-1){
            r.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++){
            swap(nums[i], nums[pos]);
            DFS(nums, r, pos+1);
            swap(nums[i], nums[pos]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        DFS(nums, r, 0);

        return r;
    }
};



int main(){
    vector<int> a{1,2,3};
    Solution s;
    vector<vector<int>> r = s.permute(a);

    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
