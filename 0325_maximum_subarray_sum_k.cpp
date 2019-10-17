class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxi = 0, n = nums.size();
        unordered_map<int, int> mp{{0,-1}};
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (mp.find(sum-k) != mp.end())
                maxi = max(maxi, i-mp[sum-k]);
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        
        return maxi;
    }
};
