#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], sum = nums[0];
        for (int i = 1; i < n; i++){
            if (sum > 0)
                sum += nums[i];
            else 
                sum = nums[i];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};



int main(){
    vector<int> a{-2,-1};
    Solution s;
    cout << s.maxSubArray(a) << endl;

    return 0;
}
