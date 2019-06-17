#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;

        int i=0, j=0;
        while (j < nums.size()){
            while (j < nums.size() && nums[j] == val)
                j++;
            while (j < nums.size() && nums[j] != val)
                nums[i++] = nums[j++];
        }
       
        return i;
    }
};


int main(){
    vector<int> a{1,2,4,6,8,2,2,5,6,8,9,0,4};
    int val = 2;
    Solution s;
    cout << s.removeElement(a, val) << endl;

    return 0;
}
