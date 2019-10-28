#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while (nums[i] != i+1 && nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        vector<int> r;
        for (int i = 0; i < n; i++)
            if (nums[i] != i+1) r.push_back(i+1);

        return r;
    }
};



int main(){
    vector<int> a{4,3,2,7,8,3,1};
    Solution s;
    vector<int> b = s.findDisappearedNumbers(a);
    for (int& i : b)
        cout << i << " ";
    cout << endl;

    return 0;
}
