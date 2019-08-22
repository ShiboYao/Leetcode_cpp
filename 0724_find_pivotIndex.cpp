#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int left = 0, right = 0;
        for (int j = 0; j < nums.size(); j++)
            right += nums[j];
        int i = 0;
        while (i < nums.size()){
            left += nums[i];
            if (left == right)
                return i;
            right -= nums[i++];
        }

        return -1;
    }
};



int main(){
    vector<int> a{-1,-1,-1,-1,-1,-1};
    Solution s;
    int r = s.pivotIndex(a);
    cout << r << endl;

    return 0;
}
