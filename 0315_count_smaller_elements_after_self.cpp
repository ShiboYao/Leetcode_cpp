#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<int>{};
        vector<int> r(n), t{nums[n-1]};
        for (int i = n-2; i >= 0; i--){
            int p = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
            r[i] = p;
            t.insert(t.begin()+p,nums[i]);
        }

        return r;
    }
};



int main(){
    vector<int> a{5,2,6,1};
    Solution s;
    vector<int> r = s.countSmaller(a);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
