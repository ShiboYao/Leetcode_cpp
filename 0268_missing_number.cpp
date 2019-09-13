#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] < n && nums[i] != i){
                swap(nums[i], nums[nums[i]]);
                i--;
            }
        }
        int i = 0;
        while (i < n && nums[i] == i)
            i++;

        return i;
    }
};



int main(){
    vector<int> a{9,6,4,2,3,5,7,0,1};
    Solution s;
    cout << s.missingNumber(a) << endl;

    return 0;
}
