#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size()==1)
            return;
        int i = 0, j = nums.size()-1, k = i;
        while (k <= j){
            if (nums[k] == 0)
                swap(nums[k++], nums[i++]);
            else if (nums[k] == 2)
                swap(nums[k], nums[j--]);
            else
                k++;
        }
    }
};



int main(){
    vector<int> a{2,0,1};
    Solution s;
    s.sortColors(a);
    for (int& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
