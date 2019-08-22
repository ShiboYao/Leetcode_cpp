#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
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
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int r = 0;
        unordered_map<int, int> mp = {{0, 1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            r += mp[sum - k];
            mp[sum]++;
        }

        return r;
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
