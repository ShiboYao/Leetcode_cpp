#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 1;
        for (int i = 0; i < n; i++){
            if (nums[i] > 0 && nums[i]-1 < n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        int i = 0;
        while (i < n && nums[i] == i+1)
            i++;

        return i+1;
    }
};



int main(){
    //vector<int> a{7,8,9};
    vector<int> a{3,4,-1,1};
    Solution s;
    cout << s.firstMissingPositive(a) << endl;

    return 0;
}
