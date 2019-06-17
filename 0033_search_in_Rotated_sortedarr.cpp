#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    int bsearch(vector<int>& nums, int left, int right, int target){
        if (left > right)
            return -1;

        cout << "left: " << nums[left] << endl;
        cout << "right: " << nums[right] << endl;
        int mid = (left+right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target){
            if (nums[left] < nums[mid] || nums[right] >= target)
                return bsearch(nums, mid+1, right, target);
            else
                return bsearch(nums, left, mid-1, target);
        }
        else {
            if (nums[right] > nums[mid] || nums[left] <= target)
                return bsearch(nums, left, mid-1, target);
            else
                return bsearch(nums, mid+1, right, target);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        return bsearch(nums, 0, nums.size()-1, target);
    }
};


int main(){
    vector<int> a{4,5,6,7,0,1,2};
    int target = 6;
    Solution s;
    cout << s.search(a, target) << endl;

    return 0;
}
