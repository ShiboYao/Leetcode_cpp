#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right){
            mid = (left+right) / 2;
            //cout << nums[mid] << endl;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target){
                if (nums[left] <= target || nums[left] > nums[mid])
                    right = mid-1;   
                else if (nums[left] > target && nums[left] < nums[mid])
                    left = mid+1;
                else
                    left++;
            }   
            else {
                if (nums[right] >= target || nums[right] < nums[mid])
                    left = mid+1;
                else if (nums[right] < target && nums[right] > nums[mid])
                    right = mid-1;
                else
                    right--;
            }   
        }   

        return false;
    }   
};


int main(){
    vector<int> a{2,5,6,0,0,1,2};
    int target = 1;
    Solution s;
    cout << s.search(a, target) << endl;

    return 0;
}
