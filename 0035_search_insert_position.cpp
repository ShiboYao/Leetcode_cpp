#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low < high){
            int mid = (low+high)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        
        return nums[low]<target?low+1:low;
    }
};



int main(){
    vector<int> nums{1,3,5,6};
    int t = 0;
    Solution s;
    cout << s.searchInsert(nums, t) << endl;

    return 0;
}
