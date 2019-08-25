#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int n = nums.size()/2;
        if (nums.size()%2)
            n++;
        for (auto p : mp){
            if (p.second >= n)
                return p.first;
        }

        return 0;
    }
};



int main(){
    vector<int> a{2,2,1,1,1,2,2};
    Solution s;
    cout << s.majorityElement(a) << endl;

    return 0;
}
