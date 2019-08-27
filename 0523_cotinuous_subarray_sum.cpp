#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        int i = 0;
        int sum = 0;
        unordered_map<int, int> mp{{0,-1}};
        k = abs(k);
        while (i < nums.size()){
            sum += nums[i];
            if (k != 0)
                sum %= k;
            if (mp.count(sum) && mp[sum] < i-1)
                return true;
            else
                mp[sum] = i;
            i++;
        }

        return false;
    }
};



int main(){
    vector<int> a{23,2,4,6,7};
    int k = 6;
    Solution s;
    cout << s.checkSubarraySum(a, k) << endl;

    return 0;
}
