#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0, j, count = 0;
        while (i < nums.size()){
            j = i++;
            int t = 0;
            while (j < nums.size()){
                t += nums[j++];
                if (t == k)
                    count++;
            }
        }

        return count;
    }
};



int main(){
    vector<int> nums = {1,1,1};
    int k = 2;
    Solution s;
    int r = s.subarraySum(nums, k);
    cout << r << endl;

    return 0;
}
