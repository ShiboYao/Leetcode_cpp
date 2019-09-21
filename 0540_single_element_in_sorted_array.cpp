#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while (low <= high){
            mid = (low+high)/2;
            bool odd = mid%2;
            if (odd){
                if (nums[mid] == nums[mid-1])
                    low = mid+1;
                else if (nums[mid] == nums[mid+1])
                    high = mid-1;
                else 
                    break;
            }
            else {
                if (mid == 0 || mid == n-1)
                    break;
                else if (nums[mid] == nums[mid-1])
                    high = mid-1;
                else if (nums[mid] == nums[mid+1])
                    low = mid+1;
                else
                    break;
            }
        }

        return nums[mid];
    }
};



int main(){
    //vector<int> a{1,1,2,3,3,4,4,8,8};
    vector<int> a{3,3,7,7,10,11,11};
    Solution s;
    cout << s.singleNonDuplicate(a) << endl;

    return 0;
}
