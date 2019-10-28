#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {        
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n > 2) nums[2] += nums[0];
        for (int i = 3; i < n; i++)
            nums[i] += max(nums[i-2],nums[i-3]);

        return max(nums[n-1],nums[n-2]);
    }
};



int main(){
    vector<int> a{2,7,9,3,1};
    Solution s;
    cout << s.rob(a) << endl;

    return 0;
}
