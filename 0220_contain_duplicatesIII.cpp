#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k && i - k - 1 < nums.size()) 
                window.erase(nums[i - k - 1]);
            auto it = window.lower_bound((long)nums[i] - t);
            if (it != window.end() && *it - nums[i] <= t) 
                return true;
            window.insert(nums[i]);
        }

        return false;
    }
};



int main(){
    //vector<int> a{1,2,3,1};
    //int k = 3, t = 0;
    //vector<int> a{1,0,1,1};
    //int k = 1, t = 2;
    vector<int> a{1,5,9,1,5,9};
    int k = 2, t = 3;
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(a, k, t) << endl;

    return 0;
}
