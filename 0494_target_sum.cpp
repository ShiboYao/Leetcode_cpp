#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int util(vector<int>& nums, int S){
        vector<int> a(S+1);
        a[0] = 1;
        for (int& n : nums){
            for (int i = S; i >= n; i--)
                a[i] += a[i-n];
        }

        return a[S];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum+S)%2)
            return 0;
        return util(nums, (sum+S)/2);
    }
};



int main(){
    vector<int> a{1,1,1,1,1};
    int t = 3;
    Solution s;
    cout << s.findTargetSumWays(a, t) << endl;

    return 0;
}
