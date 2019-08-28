#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};



int main(){
    vector<int> a{1,2,3,4,5,6,7};
    int k = 3;
    Solution s;
    s.rotate(a, k);
    for (int& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
