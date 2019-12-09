#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        k++;
        int i = 0, n = nums.size();
        while (i < n && i < k){
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            i++;
        }
        while (i < n){
            s.erase(nums[i-k]);
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            i++;
        }

        return false;
    }
};



int main(){
    vector<int> a{1,2,3,1};
    int k = 2;
    Solution s;
    cout << s.containsNearbyDuplicate(a, k) << endl;

    return 0;
}
