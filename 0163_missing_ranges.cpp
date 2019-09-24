#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int i = 0, n = nums.size();
        vector<string> r;
        if (n == 0){
            if (lower == upper)
                r.push_back(to_string(lower));
            else
                r.push_back(to_string(lower) + "->" + to_string(upper));
        }
        


        if (lower < nums[0]){
            if (lower + 1 == nums[0])
                r.push_back(to_string(lower));
            else 
                r.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        while (i < n-1){
            long a = nums[i];
            if (a + 1 < nums[i+1]){
                if (nums[i] + 2 == nums[i+1])
                    r.push_back(to_string(nums[i]+1));
                else
                    r.push_back(to_string(nums[i]+1) + "->" + to_string(nums[i+1]-1));
            }
            i++;
        }
        if (nums[i] < upper){
            if (nums[i] + 1 == upper)
                r.push_back(to_string(upper));
            else
                r.push_back(to_string(nums[i]+1) + "->" + to_string(upper));
        }

        return r;
    }
};



int main(){
    vector<int> a{0,1,3,50,75};
    int lower = 0, upper = 99;
    Solution s;
    vector<string> r = s.findMissingRanges(a, lower, upper);
    for (string i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
