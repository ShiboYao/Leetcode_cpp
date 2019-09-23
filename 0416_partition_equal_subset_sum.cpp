#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    bool util(vector<int>& nums, int S){
        vector<unsigned long long> a(S+1);
        a[0] = 1;
        for (int& n : nums){
            for (int i = S; i >= n; i--)
                a[i] += a[i-n];
            if (a[S] > 1)
                return true;
        }

        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)
            return false;

        return util(nums, sum/2);
    }
};



int main(){
    //vector<int> a{1,5,11,5};
    //vector<int> a{1,2,3,5};
    vector<int> a{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};
    Solution s;
    cout << s.canPartition(a) << endl;

    return 0;
}
