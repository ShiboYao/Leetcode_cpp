#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        int l = 0, max_len = 1;
        int i = 1;
        while (i < nums.size()){
            while (i < nums.size() && nums[i] > nums[i-1])
                i++;
            max_len = max(max_len, i-l);
            l = i++;
        }

        return max_len;
    }
};



int main(){
    vector<int> a{1,3,5,4,7};
    Solution s;
    int b = s.findLengthOfLCIS(a);
    cout << b << endl;

    return 0;
}
