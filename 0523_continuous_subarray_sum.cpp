#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{0,-1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (k != 0)
                sum %= k;
            if (mp.count(sum)){
                if (mp[sum] < i-1)
                    return true;
            }
            else
                mp[sum] = i;
        }

        return false;
    }
};



int main(){
    vector<int> a{0,1,0};
    int k = -1;
    Solution s;
    cout << s.checkSubarraySum(a, k) << endl;

    return 0;
}
