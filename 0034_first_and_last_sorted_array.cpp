#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> r;
        int low = 0, high = nums.size()-1;
        int mid;
        while (low <= high){
            mid = low + (high-low)/2;
            if (nums[mid] == target){
                if (mid == 0 || nums[mid-1] != target){
                    r.push_back(mid);
                    break;
                }
                else
                    high = mid-1;
            }
            else if (nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        if (low > high){
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        low = mid; 
        high = nums.size()-1;
        
        while (low <= high){
            mid = low + (high-low)/2;
            if (nums[mid] == target){
                if (mid == high || nums[mid+1] != target){
                    r.push_back(mid);
                    break;
                }
                else
                    low = mid+1;
            }
            else if (nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        
        return r;
    }
};

/*
class Solution {
public:
    int find(vector<int> nums, int low, int high, int target){
        if (low > high)
            return -1;
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return find(nums, low ,mid-1, target);
        else
            return find(nums, mid+1, high, target);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int mid = find(nums, 0, high, target);
        vector<int> r;
        if (mid == -1){
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        int t = mid;
        cout << t << endl;
        while (t > 0 && nums[t-1]==target)
            t = find(nums, 0, t-1, target);
        r.push_back(t);
        t = mid;
        while (t < high && nums[t+1]==target)
            t = find(nums, t+1, high, target);
        r.push_back(t);

        return r;
    }
};
*/


int main(){
    vector<int> nums{2,2};
    int target = 2;
    Solution s;
    vector<int> r = s.searchRange(nums, target);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
