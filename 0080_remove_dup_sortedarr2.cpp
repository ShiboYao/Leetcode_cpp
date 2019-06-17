#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        
        int count = 0;
        for (int i = 2; i < nums.size(); i++){
            if (nums[i-2-count] == nums[i])
                count++;
            else 
                nums[i-count] = nums[i];
        }
        
        return nums.size()-count;
    }
};


int main(){
    vector<int> a{1,2,2,2,3,3,4,4,4,4,5,6};
    Solution s;
    int l = s.removeDuplicates(a);
    for (int i=0; i < l; i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
