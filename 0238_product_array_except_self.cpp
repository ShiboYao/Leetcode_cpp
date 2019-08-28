#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++)
            nums[i] *= nums[i-1];
        for (int i = n-2; i >= 0; i--)
            r[i] *= r[i+1];
        int i = 1;
        r[i-1] = r[i];
        i++;
        while (i < n){
            r[i-1] = nums[i-2]*r[i];
            i++;
        }
        r[i-1] = nums[i-2];

        return r;
    }
};



int main(){
    vector<int> a{1,2,3,4};
    Solution s;
    vector<int> r = s.productExceptSelf(a);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
