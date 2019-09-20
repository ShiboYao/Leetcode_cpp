#include <iostream>
#include <vector>
using namespace std;

/*
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
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while (low <= high){
            while (low < high && nums[low] == nums[low+1]) low++;
            while (low < high && nums[high] == nums[high-1]) high--;
            mid = (low+high)/2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[high]){
                if (nums[mid] > target && nums[low] <= target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if (nums[mid] < nums[low]){
                if (nums[mid] < target && nums[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;
            }
            else {
                if (nums[mid] > target)
                    high = mid-1;
                else
                    low = mid+1;
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
