#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> raw(nums.size());
        raw = nums;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        vector<int> result;
        while (i < j){
            int sum = nums[i]+nums[j];
            if (sum == target){
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                break;
            }
            else if (sum > target)
                j--;
            else
                i++;
        }
        vector<int> r;
        for (int k = 0; k < raw.size(); k++){
            if (raw[k] == result[0]){
                r.push_back(k);
            }
            else if (raw[k] == result[1]){
                r.push_back(k);
            }
        }

        return r;
    }
};


int main(){
    vector<int> a{-18, 12, 3, 0};
    int target = -6;
    Solution s;
    vector<int> result = s.twoSum(a, target);
    for (auto i:result)
        cout << i << " ";
    cout << '\n';

    return 0;
}
