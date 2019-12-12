#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(), cur = nums[0];
        vector<string> r;
        r.push_back(to_string(cur));
        for (int i = 1; i < n; i++){
            if (nums[i] - nums[i-1] > 1){
                if (nums[i-1] > cur)
                    r.back() += "->"+to_string(nums[i-1]);
                r.push_back(to_string(nums[i]));
                cur = nums[i];
            }
        }
        if (n > 1 && nums[n-1] == nums[n-2]+1)
            r.back() += "->"+to_string(nums[n-1]);

        return r;
    }
};



int main(){
    //vector<int> a{0,1,2,4,5,7};
    vector<int> a{0,2,3,4,6,8,9};
    Solution s;
    vector<string> r = s.summaryRanges(a);
    for (string& i : r)
        cout << i << endl;

    return 0;
}
