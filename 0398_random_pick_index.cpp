#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
using namespace std;


class Solution {
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }

    int pick(int target) {
        srand(time(NULL));
        vector<int> t;
        for (auto i : mp[target])
            t.push_back(i);
        return t[rand()%t.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


int main(){
    vector<int> a{1,2,3,3,3};
    Solution* obj = new Solution(a);
    cout << obj->pick(3) << endl;
    cout << obj->pick(2) << endl;

    return 0;
}
