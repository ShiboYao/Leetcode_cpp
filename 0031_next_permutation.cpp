#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto i = nums.end()-2;
        while (i >= nums.begin() && *i >= *(i+1))
            i--;
        if (i >= nums.begin()){
            auto j = nums.end()-1;
            while (j > nums.begin() && *j <= *i)
                j--;
            swap(*i, *j);
            reverse(i+1, nums.end());
        }
        else
            reverse(nums.begin(), nums.end());
    }
};



int main(){
    vector<int> a{1,1,5};
    Solution s;
    s.nextPermutation(a);
    for (int& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
